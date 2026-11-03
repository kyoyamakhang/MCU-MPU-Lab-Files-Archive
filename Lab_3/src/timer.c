#include "main.h"
#include "input_reading.h"
#include "timer.h"

int tick = 10;
int counterTimer0 = 0;
int flagTimer0 = 0;
int counterTimer1 = 0;
int flagTimer1 = 0;
int counterTimer2 = 0;
int flagTimer2 = 0;
int counter = 50;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {
	if(htim->Instance == TIM2) {
		button_reading();
	}
	timer_run();
	counter--;
	if(counter <= 0) {
		counter = 50;
	}
}
void setTimer0_fixed() {
	counterTimer0 = 250/tick;
	flagTimer0 = 0;
}
void setTimer1(int num) {
	counterTimer1 = num/tick;
	flagTimer1 = 0;
}
void clearTimer0_fixed() {
	counterTimer0 = 0;
	flagTimer0 = 0;
}
void clearTimer1() {
	counterTimer1 = 0;
	flagTimer1 = 0;
}
void setTimer2(int num) {
	counterTimer2 = num/tick;
	flagTimer2 = 0;
}
void clearTimer2() {
	counterTimer2 = 0;
	flagTimer2 = 0;
}


void timer_run() {
	if(counterTimer0 > 0) {
		counterTimer0--;
		if(counterTimer0 == 0) flagTimer0 = 1;
	}
	if(counterTimer1 > 0) {
		counterTimer1--;
		if(counterTimer1 == 0) flagTimer1 = 1;
	}
	if(counterTimer2 > 0) {
		counterTimer2--;
		if(counterTimer2 == 0) flagTimer2 = 1;
	}
}
