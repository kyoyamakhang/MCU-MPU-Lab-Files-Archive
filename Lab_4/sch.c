/*
 * sch.c
 *
 *  Created on: Nov 8, 2026
 *      Author: LOQ
 */

#include "sch.h"

extern TIM_HandleTypeDef htim2;   // timer made by CubeMX (change if you use another)

sTask SCH_tasks_G[SCH_MAX_TASKS];
volatile uint32_t timestamp = 0;     // time in ms, increases by TICK_MS every tick
uint32_t Next_Task_ID = 1;
unsigned char Error_code_G = 0;
int SCH_head = -1;   // index of the first task in the list, -1 = list empty

#ifdef SCH_REPORT_ERRORS
unsigned char Last_error_code_G = 0;
uint32_t Error_tick_count_G = 0;
// CHANGE THIS to the port that has your error LEDs (it writes the whole port!)
#define Error_port (GPIOB->ODR)
#endif

void SCH_Init(void) {
    unsigned char i;
    for (i = 0; i < SCH_MAX_TASKS; i++) {
        SCH_tasks_G[i].pTask  = 0;
        SCH_tasks_G[i].Delay  = 0;
        SCH_tasks_G[i].Period = 0;
        SCH_tasks_G[i].TaskID = 0;
        SCH_tasks_G[i].Next   = -1;
    }
    SCH_head = -1;
    Error_code_G = 0;
    timestamp = 0;
    Next_Task_ID = 1;

    HAL_TIM_Base_Start_IT(&htim2);
#ifdef SCH_USE_WATCHDOG
    MX_IWDG_Init();
#endif
}

void SCH_Go_To_Sleep(void) {
    // todo: optional
}

void SCH_Update(void) {
    timestamp += TICK_MS;
    if (SCH_head != -1) {
        if (SCH_tasks_G[SCH_head].Delay > 0) {
            SCH_tasks_G[SCH_head].Delay -= 1;
        }
    }
}

void SCH_Insert_Node(int newIndex) {
    int prev = -1;
    int cur = SCH_head;
    uint32_t d = SCH_tasks_G[newIndex].Delay;

    // walk past every task that is due before (or at the same time as) the new one
    while ((cur != -1) && (SCH_tasks_G[cur].Delay <= d)) {
        d -= SCH_tasks_G[cur].Delay;
        prev = cur;
        cur = SCH_tasks_G[cur].Next;
    }

    SCH_tasks_G[newIndex].Delay = d;
    SCH_tasks_G[newIndex].Next = cur;
    if (cur != -1) {
        SCH_tasks_G[cur].Delay -= d;   // the task after it now waits from the new one
    }
    if (prev == -1) {
        SCH_head = newIndex;
    } else {
        SCH_tasks_G[prev].Next = newIndex;
    }
}

uint32_t SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD) {
    int Index = 0;
    uint32_t id;

    __disable_irq();
    while ((Index < SCH_MAX_TASKS) && (SCH_tasks_G[Index].pTask != 0)) {
        Index++;
    }
    if (Index == SCH_MAX_TASKS) {
        Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
        __enable_irq();
        return NO_TASK_ID;
    }

    id = Next_Task_ID;
    Next_Task_ID++;

    SCH_tasks_G[Index].pTask  = pFunction;
    SCH_tasks_G[Index].Delay  = DELAY / TICK_MS;
    SCH_tasks_G[Index].Period = PERIOD / TICK_MS;
    SCH_tasks_G[Index].TaskID = id;
    SCH_tasks_G[Index].Next   = -1;
    SCH_Insert_Node(Index);
    __enable_irq();

    return id;
}

void SCH_Dispatch_Tasks(void) {
    int index;
    uint32_t id;
    void (*pFunction)(void);

    while (1) {
        __disable_irq();
        index = SCH_head;
        if ((index == -1) || (SCH_tasks_G[index].Delay != 0)) {
            __enable_irq();
            break;                                  // nothing due now
        }
        SCH_head = SCH_tasks_G[index].Next;         // take it out of the list
        pFunction = SCH_tasks_G[index].pTask;
        id = SCH_tasks_G[index].TaskID;
        __enable_irq();

        (*pFunction)();                             // run the task

        __disable_irq();
        if ((SCH_tasks_G[index].pTask != 0) && (SCH_tasks_G[index].TaskID == id)) {
            if (SCH_tasks_G[index].Period > 0) {
                SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period;
                SCH_tasks_G[index].Next = -1;
                SCH_Insert_Node(index);             // periodic: put it back
            } else {
                SCH_tasks_G[index].pTask  = 0;      // one-shot: free the slot
                SCH_tasks_G[index].Delay  = 0;
                SCH_tasks_G[index].Period = 0;
                SCH_tasks_G[index].TaskID = 0;
                SCH_tasks_G[index].Next   = -1;
            }
        }
        __enable_irq();
    }

    SCH_Report_Status();
    SCH_Go_To_Sleep();
}

uint8_t SCH_Delete_Task(uint32_t taskID) {
    uint8_t Return_code = RETURN_ERROR;
    int index = -1;
    int prev = -1;
    int cur;
    int i;

    if (taskID != NO_TASK_ID) {
        __disable_irq();
        for (i = 0; i < SCH_MAX_TASKS; i++) {
            if ((SCH_tasks_G[i].pTask != 0) && (SCH_tasks_G[i].TaskID == taskID)) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            // find it in the list (it is not there if it is running right now)
            cur = SCH_head;
            while ((cur != -1) && (cur != index)) {
                prev = cur;
                cur = SCH_tasks_G[cur].Next;
            }
            if (cur == index) {
                if (SCH_tasks_G[index].Next != -1) {
                    SCH_tasks_G[SCH_tasks_G[index].Next].Delay += SCH_tasks_G[index].Delay;
                }
                if (prev == -1) {
                    SCH_head = SCH_tasks_G[index].Next;
                } else {
                    SCH_tasks_G[prev].Next = SCH_tasks_G[index].Next;
                }
            }
            SCH_tasks_G[index].pTask  = 0;
            SCH_tasks_G[index].Delay  = 0;
            SCH_tasks_G[index].Period = 0;
            SCH_tasks_G[index].TaskID = 0;
            SCH_tasks_G[index].Next   = -1;
            Return_code = RETURN_NORMAL;
        }
        __enable_irq();
    }

    if (Return_code == RETURN_ERROR) {
        Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
    }
    return Return_code;
}

void SCH_Report_Status(void) {
#ifdef SCH_REPORT_ERRORS
    // check for a new error code
    if (Error_code_G != Last_error_code_G) {
        // negative logic on LEDs assumed
        Error_port = 255 - Error_code_G;
        Last_error_code_G = Error_code_G;
        if (Error_code_G != 0) {
            Error_tick_count_G = 60000;
        } else {
            Error_tick_count_G = 0;
        }
    } else {
        if (Error_tick_count_G != 0) {
            if (--Error_tick_count_G == 0) {
                Error_code_G = 0;   // reset error code
            }
        }
    }
#endif
}

uint32_t get_time(void) {
    return timestamp;
}

#ifdef SCH_USE_WATCHDOG
IWDG_HandleTypeDef hiwdg;   // delete this and MX_IWDG_Init if CubeMX already made them
static uint32_t counter_for_watchdog = 0;

void MX_IWDG_Init(void) {
    hiwdg.Instance = IWDG;
    hiwdg.Init.Prescaler = IWDG_PRESCALER_32;
    hiwdg.Init.Reload = 4095;
    if (HAL_IWDG_Init(&hiwdg) != HAL_OK) {
        Error_Handler();
    }
}

void Watchdog_Refresh(void) {
    HAL_IWDG_Refresh(&hiwdg);
}

unsigned char Is_Watchdog_Reset(void) {
    if (counter_for_watchdog > 3) {
        return 1;
    }
    return 0;
}

void Watchdog_Counting(void) {
    counter_for_watchdog++;
}

void Reset_Watchdog_Counting(void) {
    counter_for_watchdog = 0;
}
#endif

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM2) {
        SCH_Update();
    }
}
