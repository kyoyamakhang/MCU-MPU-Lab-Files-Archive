#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

enum FSM_State {MODE_1, MODE_2, MODE_3, MODE_4};
typedef enum FSM_State State_FSM;

enum ButtonState {BUTTON_RELEASED , BUTTON_PRESSED ,BUTTON_PRESSED_MORE_THAN_1_SECOND};
typedef enum ButtonState BState;

extern State_FSM FSM_state;
extern int redTime, yellowTime, greenTime;
extern int tempValue;


void fsm_for_input_processing (void);

#endif /* INC_INPUT_PROCESSING_H_ */
