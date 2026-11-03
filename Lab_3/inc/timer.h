#ifndef TIMER_H_
#define TIMER_H_

#include "main.h"
extern int flagTimer0;
extern int flagTimer1;
extern int flagTimer2;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim);
void timer_run();
void setTimer0_fixed();
void clearTimer0_fixed();
void setTimer1(int num);
void clearTimer1();
void setTimer2(int num);
void clearTimer2();
// in timer_run():

#endif /* TIMER_H_ */
