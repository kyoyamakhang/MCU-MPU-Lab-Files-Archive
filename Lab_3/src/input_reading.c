#include "main.h"
#include "input_reading.h"
#define N0_OF_BUTTONS 3
#define DURATION_FOR_AUTO_INCREASING 100
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

static GPIO_PinState buttonBuffer[N0_OF_BUTTONS] = {GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET};;
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS] = {GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET};
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS] = {GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_SET};
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];
static int buttons[3] = {GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_15};

void button_reading(void){
	for(char i = 0; i < N0_OF_BUTTONS ; i++){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(GPIOB , buttons[i]);
		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]) buttonBuffer[i] = debounceButtonBuffer1[i];
		if(buttonBuffer[i] == BUTTON_IS_PRESSED){
	// if a button is pressed , start counting
			//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
			if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING){
				counterForButtonPress1s[i]++;
			} else {
	// the flag is turned on when 1 second has passed
	// since the button is pressed .
				flagForButtonPress1s[i] = 1;
	// todo
			}
		} else {
			counterForButtonPress1s[i] = 0;
			flagForButtonPress1s[i] = 0;
		}
	}
}

unsigned char is_button_pressed(uint8_t index) {
	if(index >= N0_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}
unsigned char is_button_pressed_1s(unsigned char index) {
	if(index >= N0_OF_BUTTONS) return 0xff;
	return (flagForButtonPress1s[index] == 1);
}
