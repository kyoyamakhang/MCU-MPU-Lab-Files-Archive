#ifndef INPUT_PROCESSING_C_
#define INPUT_PROCESSING_C_

#include "main.h"
#include "input_reading.h"
#include "input_processing.h"

State_FSM FSM_state = MODE_1;   // default
int redTime = 5;
int yellowTime = 3;
int greenTime = 2;
int tempValue = 1;              // value being changed in mode 2, 3, 4

int press0 = 0;                 // 1 means this press was already handled
int press1 = 0;
int press2 = 0;

void fsm_for_input_processing(void){
	// button 0: change mode
	if(is_button_pressed(0)){
		if(press0 == 0){
			press0 = 1;
			FSM_state = (FSM_state + 1) % 4;
			if(FSM_state == MODE_2) tempValue = redTime;
			if(FSM_state == MODE_3) tempValue = yellowTime;
			if(FSM_state == MODE_4) tempValue = greenTime;
		}
	} else {
		press0 = 0;
	}

	// button 1: increase value (only in mode 2, 3, 4)
	if(is_button_pressed(1)){
		if(press1 == 0){
			press1 = 1;
			if(FSM_state != MODE_1){
				tempValue++;
				if(tempValue > 99) tempValue = 1;
			}
		}
	} else {
		press1 = 0;
	}

	// button 2: set value (only in mode 2, 3, 4)
	if(is_button_pressed(2)){
		if(press2 == 0){
			press2 = 1;
			switch(FSM_state){
				case MODE_2:
					redTime = tempValue;
					break;
				case MODE_3:
					yellowTime = tempValue;
					break;
				case MODE_4:
					greenTime = tempValue;
					break;
				default:
					break;
			}
		}
	} else {
		press2 = 0;
	}
}
#endif
