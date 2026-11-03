/*
 * 7Seg_display.c
 *
 *  Created on: Oct 25, 2026
 *      Author: Thinkpad X1 Carbon
 */
#include "7Seg_display.h"
#include "timer.h"

void display7SEG_PB(int num) {
	switch(num) {
	case 0:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET		); // D
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET		); // E
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET		); // F
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET			); // G
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET			); // A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET			); // D
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET			); // E
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET			); // F
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET			); // G
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET		); // C
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET			); // D
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET			); // E
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET		); // F
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET			); // G
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET		); // D
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET			); // E
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET			); // F
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET		); // G
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET			); // A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET			); // D
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET			); // E
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET		); // F
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET		); // G
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET			); // B
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET		); // D
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET			); // E
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET		); // F
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET		); // G
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET			); // B
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET		); // D
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET		); // E
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET		); // F
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET		); // G
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET			); // D
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET			); // E
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET			); // F
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET			); // G
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET		); // D
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET		); // E
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET		); // F
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET		); // G
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET		); // D
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET			); // E
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET		); // F
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET		); // G
		break;
	default:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET		); // D
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET		); // E
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET		); // F
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET		); // G
		break;
}
};
void display7SEG_PA(int num) {
	switch(num) {
	case 0:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET		); // D
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET		); // E
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET		); // F
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_SET			); // G
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET			); // A
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET			); // D
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET			); // E
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET			); // F
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_SET			); // G
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET		); // C
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET			); // D
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET			); // E
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET		); // F
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET			); // G
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET		); // D
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET			); // E
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET			); // F
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET		); // G
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET			); // A
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET			); // D
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET			); // E
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET		); // F
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET		); // G
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET			); // B
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET		); // D
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET			); // E
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET		); // F
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET		); // G
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET			); // B
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET		); // D
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET		); // E
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET		); // F
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET		); // G
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET			); // D
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET			); // E
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET			); // F
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_SET			); // G
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET		); // D
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET		); // E
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET		); // F
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET		); // G
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET		); // D
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET			); // E
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET		); // F
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET		); // G
		break;
	default:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET			); // A
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET			); // B
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET		); // C
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET		); // D
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET		); // E
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_RESET		); // F
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, GPIO_PIN_RESET		); // G
		break;
}
};
void TrafficLight_4Way(void) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET	); // TLA RED
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET	);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET	);
	// ----------------------
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET	); // Trafic light B green
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET	);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET	);
	HAL_Delay(2000);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET	); // Trafic light B yellow
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET	);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET	);
	HAL_Delay(3000); // 5s total delay for RED
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET	); // Trafic light B red
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET	);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET	);
	// ----------------------
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET	);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET	);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET	);
	HAL_Delay(2000); // 2s delay for GREEN
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET	);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET	);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET	);
	HAL_Delay(3000); // 3s delay for YELLOW
};
void TrafficLight_7LED_Display(int* state, int* countA, int* countB) {
	switch (*state)
	  {
		  case 2:     // A RED - B GREEN
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);

			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);

			  (*countA)--;
			  (*countB)--;

			  if (*countB == 0)
			  {
				  *state = 3;
				  *countB = yellowTime;
			  }
			  break;
		  case 3:     // A RED - B YELLOW
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

			  (*countA)--;
			  (*countB)--;

			  if (*countB == 0)
			  {
				  *state = 0;
				  *countA = greenTime;
				  *countB = redTime;
			  }
			  break;
		  case 0:     // A GREEN - B RED
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);

			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

			  (*countA)--;
			  (*countB)--;

			  if (*countA == 0)
			  {
				  *state = 1;
				  *countA = yellowTime;
			  }
			  break;
		  case 1:     // A YELLOW - B RED
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);

			  (*countA)--;
			  (*countB)--;

			  if (*countA == 0)
			  {
				  *state = 2;
				  *countA = redTime;
				  *countB = greenTime;
			  }
			  break;
	  }
};

static int scanIndex = 0;

void scan7SEG(int valueA, int valueB) {
	if (flagTimer2 != 1) return;
	setTimer2(SCAN_PERIOD_MS);

	HAL_GPIO_WritePin(EN_A_PORT, EN_A_TENS_PIN | EN_A_UNITS_PIN, EN_OFF);
	HAL_GPIO_WritePin(EN_B_PORT, EN_B_TENS_PIN | EN_B_UNITS_PIN, EN_OFF);
	if (scanIndex == 0) {
		display7SEG_PA(valueA / 10);
		display7SEG_PB(valueB / 10);
		HAL_GPIO_WritePin(EN_A_PORT, EN_A_TENS_PIN, EN_ON);
		HAL_GPIO_WritePin(EN_B_PORT, EN_B_TENS_PIN, EN_ON);
	} else {
		display7SEG_PA(valueA % 10);
		display7SEG_PB(valueB % 10);
		HAL_GPIO_WritePin(EN_A_PORT, EN_A_UNITS_PIN, EN_ON);
		HAL_GPIO_WritePin(EN_B_PORT, EN_B_UNITS_PIN, EN_ON);
	}
	scanIndex = !scanIndex;
}

void blink_LEDs(State_FSM st, int on) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);
	if (on) {
		uint16_t pin = (st == MODE_2) ? GPIO_PIN_5 : (st == MODE_3) ? GPIO_PIN_6 : GPIO_PIN_7;
		HAL_GPIO_WritePin(GPIOA, pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, pin, GPIO_PIN_SET);
	}
}
