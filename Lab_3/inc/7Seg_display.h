/*
 * 7Seg_display.h
 *
 *  Created on: Oct 25, 2026
 *      Author: Thinkpad X1 Carbon
 */

#ifndef INC_7SEG_DISPLAY_H_
#define INC_7SEG_DISPLAY_H_

#include "main.h"
#include "input_processing.h"

#define EN_ON  GPIO_PIN_RESET
#define EN_OFF GPIO_PIN_SET
#define EN_A_PORT       GPIOA
#define EN_A_TENS_PIN   GPIO_PIN_1
#define EN_A_UNITS_PIN  GPIO_PIN_2
#define EN_B_PORT       GPIOB
#define EN_B_TENS_PIN   GPIO_PIN_1
#define EN_B_UNITS_PIN  GPIO_PIN_2
#define SCAN_PERIOD_MS 500

void scan7SEG(int valueA, int valueB);
void blink_LEDs(State_FSM st, int on);

void display7SEG_PB(int num);
void display7SEG_PA(int num);
void TrafficLight_4Way(void);
void TrafficLight_7LED_Display(int* state, int* countA, int* countB);

void display_Mode(State_FSM st);

#endif /* 7SEG_DISPLAY_H_ */
