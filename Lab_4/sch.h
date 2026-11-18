/*
 * sch.h
 *
 *  Created on: Nov 8, 2026
 *      Author: LOQ
 */

#ifndef SCH_H
#define SCH_H

#include "main.h"

#define SCH_MAX_TASKS   40
#define NO_TASK_ID      0
#define TICK_MS         10

#define RETURN_ERROR    1
#define RETURN_NORMAL   0

#define ERROR_SCH_TOO_MANY_TASKS     1
#define ERROR_SCH_CANNOT_DELETE_TASK 2

//#define SCH_REPORT_ERRORS
//#define SCH_USE_WATCHDOG

typedef struct {
    void (*pTask)(void);   // pointer to the task
    uint32_t Delay;        // ticks to wait AFTER the previous task in the list
    uint32_t Period;       // ticks between runs (0 = one-shot)
    uint32_t TaskID;       // ID given to the user
    int Next;              // index of the next task in the list, -1 = end
} sTask;

extern unsigned char Error_code_G;

void     SCH_Init(void);
void     SCH_Update(void);
uint32_t SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD);
void     SCH_Dispatch_Tasks(void);
uint8_t  SCH_Delete_Task(uint32_t taskID);
void     SCH_Go_To_Sleep(void);
void     SCH_Report_Status(void);
void 	 SCH_Insert_Node(int newIndex);
uint32_t get_time(void);


#ifdef SCH_USE_WATCHDOG
void MX_IWDG_Init(void);
void Watchdog_Refresh(void);
unsigned char Is_Watchdog_Reset(void);
void Watchdog_Counting(void);
void Reset_Watchdog_Counting(void);
#endif

#endif /* SCH_H */
