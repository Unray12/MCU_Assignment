/*
 * fsm_tuning.c
 *
 *  Created on: Nov 22, 2023
 *      Author: HOME
 */
#include "fsm_tuning.h"

int amber_on = 0;

void fsm_tuning_run() {
	switch (status) {
		case TUNING_RED:
//			clearTrafficLight();
			if (timerFlag[3] == 1) {
				setTimer(3, 50); //blinky 2 Hz
				HAL_GPIO_TogglePin(D2_GPIO_Port, D2_Pin); //toggle red 1

				HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin); //toggle red 2
			}

			if (isButtonPressed(1) == 1) {
				currentLed13++;
				if (currentLed13 > 99)
					currentLed13 = 0;
				updateLedBuffer();
				uart_communication_fsm();
			}


			if(isButtonPressed(0) == 1) {
				clearled();
				status = TUNING_AMBER;
				//clearTrafficLight();
				currentLed24 = 3; //mode
				updateLedBuffer();
				setTimer(3, 50);
				uart_communication_fsm();
			}

			if (isButtonPressed(2) == 1) {
				realRedTime = currentLed13;
				currentLed13 = 0;

			}
			break;
		case TUNING_AMBER:
			if (timerFlag[3] == 1) {
				setTimer(3, 50);
				clearled();
				if (amber_on == 0) {
					HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET); //toggle amber 1
					HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);

					HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET); //toggle amber 2
					HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
					amber_on = 1;
				}
				else {
					HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET); //toggle amber 1
					HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);

					HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET); //toggle amber 2
					HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
					amber_on = 0;
				}
			}

			if (isButtonPressed(1) == 1) {
				currentLed13++;
				if (currentLed13 > 99)
					currentLed13 = 0;
				updateLedBuffer();
				uart_communication_fsm();
			}

			if(isButtonPressed(0) == 1) {
				clearled();
				status = TUNING_GREEN;
				clearTrafficLight();
				currentLed24 = 4; //mode
				updateLedBuffer();
				setTimer(3, 50);
				uart_communication_fsm();
			}

			if (isButtonPressed(2) == 1) {
				realAmberTime = currentLed13;
				currentLed13 = 0;
			}
			break;
		case TUNING_GREEN:
			if (timerFlag[3] == 1) {
				setTimer(3, 50);
				HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin); //toggle green led 1
				HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin); //toggle green led 2
			}


			if (isButtonPressed(1) == 1) {
				currentLed13++;
				if (currentLed13 > 99)
					currentLed13 = 0;
				updateLedBuffer();
				uart_communication_fsm();
			}

			if(isButtonPressed(0) == 1) {
				clearled();
				status = INIT;
				clearTrafficLight();
				currentLed24 = 1; //mode
				updateLedBuffer();
				setTimer(0, realAmberTime * 100);
				uart_communication_fsm();
			}

			if (isButtonPressed(2) == 1) {
				realGreenTime = currentLed13;
				currentLed13 = 0;
			}
			break;
		default:
			break;
	}
}

