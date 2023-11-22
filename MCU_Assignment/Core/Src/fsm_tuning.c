/*
 * fsm_tuning.c
 *
 *  Created on: Nov 22, 2023
 *      Author: HOME
 */
#include "fsm_tuning.h"

void fsm_tuning_run() {
	switch (status) {
		case TUNING_RED:
//			clearTrafficLight();
			if (timerFlag[3] == 1) {
				setTimer(3, 50); //blinky 2 Hz
				HAL_GPIO_TogglePin(GPIOB, D2_Pin); //toggle red 1
				HAL_GPIO_TogglePin(GPIOB, D3_Pin);

				HAL_GPIO_TogglePin(GPIOB, D4_Pin); //toggle red 2
				HAL_GPIO_TogglePin(GPIOB, D5_Pin);
			}

			if (isButtonPressed(1) == 1) {
				currentLed13++;
				if (currentLed13 > 99)
					currentLed13 = 0;
				updateLedBuffer();
			}

			if(isButtonPressed(0) == 1) {
				status = TUNING_AMBER;
				clearTrafficLight();
				currentLed24 = 3; //mode
				updateLedBuffer();
				setTimer(3, 50);
			}

			if (isButtonPressed(2) == 1) {
				realRedTime = currentLed13;
			}
			break;
		case TUNING_AMBER:
			if (timerFlag[3] == 1) {
				HAL_GPIO_TogglePin(GPIOB, D2_Pin); //toggle amber 1
				HAL_GPIO_TogglePin(GPIOB, D4_Pin); //toggle amber 2
			}

			if (isButtonPressed(1) == 1) {
				currentLed13++;
				if (currentLed13 > 99)
					currentLed13 = 0;
				updateLedBuffer();
			}

			if(isButtonPressed(0) == 1) {
				status = TUNING_GREEN;
				clearTrafficLight();
				currentLed24 = 4; //mode
				updateLedBuffer();
				setTimer(3, 50);
			}

			if (isButtonPressed(2) == 1) {
				realAmberTime = currentLed13;
			}
			break;
		case TUNING_GREEN:
			if (timerFlag[3] == 1) {
				HAL_GPIO_TogglePin(GPIOB, D3_Pin); //toggle green led 1
				HAL_GPIO_TogglePin(GPIOB, D5_Pin); //toggle green led 2
			}


			if (isButtonPressed(1) == 1) {
				currentLed13++;
				if (currentLed13 > 99)
					currentLed13 = 0;
				updateLedBuffer();
			}

			if(isButtonPressed(0) == 1) {
				status = TUNING_RED;
				clearTrafficLight();
				currentLed24 = 1; //mode
				updateLedBuffer();
				setTimer(0, realAmberTime * 100);
			}

			if (isButtonPressed(2) == 1) {
				realGreenTime = currentLed13;
			}
			break;
		default:
			break;
	}
}

