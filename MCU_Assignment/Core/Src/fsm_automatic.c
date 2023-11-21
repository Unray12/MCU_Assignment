/*
 * fsm_automatic.c
 *
 *  Created on: Nov 21, 2023
 *      Author: HOME
 */
#include "fsm_automatic.h"



int amberTime = 0; //scaled time in software timer
int	greenTime = 0;

int led13 = 0; //initial time for that state
int led24 = 0;




void redGreenLed() {
	onRed1();
	onGreen2();
}

void redAmberLed() {
	onRed1();
	onAmber2();
}

void greenRedLed() {
	onGreen1();
	onRed2();
}

void amberRedLed() {
	onAmber1();
	onRed2();
}

void fsm_automatic_run() {
	amberTime = realAmberTime * 100;
	greenTime = realGreenTime * 100;
	switch (status) {
	case INIT:
		clearTrafficLight();
		status = RED_GREEN;
		setTimer(0, greenTime);

		led13 = realAmberTime + realGreenTime;
		led24 = realGreenTime;
		break;
	case RED_GREEN:
		redGreenLed();
		if (isButtonPressed(0) == 1) {
			status = MAN_RED;
			clearTrafficLight();
			currentLed24 = 2; //mode
			updateLedBuffer();

//			setTimer(2, 10); //update leds

		}
		if (timerFlag[0] == 1){
			status = RED_AMBER;

			led13 = realAmberTime + realGreenTime;
			led24 = realAmberTime;

			setTimer(0, amberTime);
		}
		break;
	case RED_AMBER:
		redAmberLed();

		if (timerFlag[0] == 1) {
			status = GREEN_RED;

			led13 = realGreenTime;
			led24 = realAmberTime + realGreenTime;

			setTimer(0, greenTime);
		}

		isButtonPressed(0);
		break;
	case GREEN_RED:
		greenRedLed();

		if (timerFlag[0] == 1) {
			status = AMBER_RED;

			led13 = realAmberTime;
			led24 = realAmberTime + realGreenTime;

			setTimer(0, amberTime);
		}

		isButtonPressed(0);
		break;
	case AMBER_RED:
		amberRedLed();

		if (timerFlag[0] == 1) {
			status = RED_GREEN;

			led13 = realAmberTime + realGreenTime;
			led24 = realGreenTime;

			setTimer(0, greenTime);
		}

		isButtonPressed(0);
		break;
	default:
		break;
	}
	if (status <= 5) {
		if (timerFlag[1] == 1) { //for 7 seg leds buffer
			currentLed13--;
			currentLed24--;
			if (currentLed13 < 0)
				currentLed13 = led13;
			if (currentLed24 < 0)
				currentLed24 = led24;
			updateLedBuffer();
			setTimer(1, 100);
		}

	}
}

