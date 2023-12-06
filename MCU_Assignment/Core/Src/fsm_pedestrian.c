/*
 * fsm_pedestrian.c
 *
 *  Created on: Nov 25, 2023
 *      Author: Vostro
 */

#include "global.h"
#include "software_timer.h"
void fsm_pedestrian() {
	if (timerFlag[3]==1) {
		buzzer_off();
		status_pedestrian=PEDESTRIAN_GREEN;


		// change to green red
		status=AUTO_GREEN_RED;

		led13=realGreenTime;
		led24=realAmberTime+realGreenTime;

		setTimer(0,realGreenTime*100);
		///////////////////////

		setTimer(5, realGreenTime*100);
		timerFlag[3]=0;
	}
	switch(status_pedestrian) {
	case PEDESTRIAN:
		buzzer_on();
		if (status!=AUTO_RED_GREEN) {
			timerFlag[3]=1;
		}
		break;
	case PEDESTRIAN_GREEN:
		onGreenPedes();
		if (timerFlag[5]==1) {
			status_pedestrian=PEDESTRIAN_AMBER;
			setTimer(5, realAmberTime*100);
		}
		break;
	case PEDESTRIAN_AMBER:
		onAmberPedes();
		if (timerFlag[5]==1) {
			status_pedestrian=PEDESTRIAN_RED;
			setTimer(5, realRedTime*100);
		}
		break;
	case PEDESTRIAN_RED:
		onRedPedes();
		if (timerFlag[5]==1) {
			clearPedesLed();
			status_pedestrian=1000;
			timerFlag[5]=0;
		}
		break;
	default:
		break;
	}
}
