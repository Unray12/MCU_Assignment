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

void countDown() {
	if (timerFlag[1] == 1) { //for 7 seg leds buffer
		currentLed13--;
		currentLed24--;
		if (currentLed13 <= 0)
			currentLed13 = led13;
		if (currentLed24 <= 0)
			currentLed24 = led24;
		updateLedBuffer();
		setTimer(1, 100);
	}
}
void fsm_automatic_run() {
	amberTime = realAmberTime * 100;
	greenTime = realGreenTime * 100;
	switch (status) {
	case INIT:
		clearTrafficLight();
		status = AUTO_RED_GREEN;
		setTimer(0, greenTime);

		led13 = realAmberTime + realGreenTime;
		led24 = realGreenTime;
		break;
	case AUTO_RED_GREEN:
		redGreenLed();
		if (isButtonPressed(0) == 1) {
			status = MANUAL_RED_GREEN;
			clearTrafficLight();
			currentLed24 = 2; //mode
			updateLedBuffer();
			setTimer(2, 10); //update leds
			uart_communication_fsm();
		}
		if (timerFlag[0] == 1){
			status = AUTO_RED_AMBER;

			led13 = realAmberTime + realGreenTime;
			led24 = realAmberTime;

			setTimer(0, amberTime);
		}
		countDown();
		if (isButtonPressed(3)) { // pedestrian nho' check cac state khac khi bam nut
			buzzer_flag=1;
			status_pedestrian=PEDESTRIAN;
		}
		break;
	case AUTO_RED_AMBER:
		redAmberLed();

		if (isButtonPressed(0) == 1) {
			status = MANUAL_RED_AMBER;
			clearTrafficLight();
			currentLed24 = 2; //mode
			updateLedBuffer();
			setTimer(2, 10); //update leds
			uart_communication_fsm();
		}

		if (timerFlag[0] == 1) {
			status = AUTO_GREEN_RED;

			led13 = realGreenTime;
			led24 = realAmberTime + realGreenTime;

			setTimer(0, greenTime);
		}
		countDown();
		if (isButtonPressed(3)) { // pedestrian nho' check cac state khac khi bam nut
			buzzer_flag=1;
			status_pedestrian=PEDESTRIAN;
		}
		isButtonPressed(0);
		break;
	case AUTO_GREEN_RED:
		greenRedLed();

		if (isButtonPressed(0) == 1) {
			status = MANUAL_GREEN_RED;
			clearTrafficLight();
			currentLed24 = 2; //mode
			updateLedBuffer();
			setTimer(2, 10); //update leds
			uart_communication_fsm();
		}

		if (timerFlag[0] == 1) {
			status = AUTO_AMBER_RED;

			led13 = realAmberTime;
			led24 = realAmberTime + realGreenTime;

			setTimer(0, amberTime);
		}
		countDown();
		if (isButtonPressed(3)) { // pedestrian nho' check cac state khac khi bam nut
			buzzer_flag=1;
			status_pedestrian=PEDESTRIAN;
		}
		isButtonPressed(0);
		break;
	case AUTO_AMBER_RED:
		amberRedLed();

		if (isButtonPressed(0) == 1) {
			status = MANUAL_AMBER_RED;
			clearTrafficLight();
			currentLed24 = 2; //mode
			updateLedBuffer();
			setTimer(2, 10); //update leds
			uart_communication_fsm();
		}

		if (timerFlag[0] == 1) {
			status = AUTO_RED_GREEN;

			led13 = realAmberTime + realGreenTime;
			led24 = realGreenTime;

			setTimer(0, greenTime);
		}
		countDown();
		if (isButtonPressed(3)) { // pedestrian nho' check cac state khac khi bam nut
			buzzer_flag=1;
			status_pedestrian=PEDESTRIAN;
		}
		isButtonPressed(0);
		break;
	default:
		break;
	}
}

