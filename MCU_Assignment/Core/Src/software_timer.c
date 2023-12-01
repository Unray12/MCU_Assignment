/*
 * software_timer.c
 *
 *  Created on: Nov 16, 2023
 *      Author: HOME
 */

#include "software_timer.h"

uint16_t timerCounter[MAX_TIMER] = {0};
uint8_t timerFlag[MAX_TIMER] = {0};

void setTimer(uint8_t index, uint16_t duration) {
	timerCounter[index] = duration;
	timerFlag[index] = 0;
}

void timerRun(uint8_t index){
	if(timerCounter[index] > 0){
		timerCounter[index]--;
		if (timerCounter[index] <= 0){
			timerFlag[index] = 1;
		}
	}
}

void timer_run() {
	timerRun(0);
	timerRun(1);
	timerRun(2);
	timerRun(3);
	timerRun(6);
}
