/*
 * fsm_pedestrian.c
 *
 *  Created on: Nov 25, 2023
 *      Author: Vostro
 */

#include "global.h"
#include "software_timer.h"
void fsm_pedestrian() {
//	if (timerFlag[3]==1) {
//		buzzer_off();
//		status_pedestrian=PEDESTRIAN_GREEN;
//
//
//		// change to green red
//		status=AUTO_GREEN_RED;
//
//		led13=realGreenTime;
//		led24=realAmberTime+realGreenTime;
//
//		setTimer(0,realGreenTime*100);
//		///////////////////////
//
//		setTimer(5, realGreenTime*100);
//		timerFlag[3]=0;
//	}
	switch(status_pedestrian) {
	case PEDESTRIAN:
//		buzzer_on();
		if (status==AUTO_RED_GREEN || status==AUTO_RED_AMBER || status==AUTO_AMBER_RED) {
			status_pedestrian=PEDESTRIAN_RED;
		} else if (status==AUTO_GREEN_RED) {
			status_pedestrian=PEDESTRIAN_GREEN;
		}
		break;
	case PEDESTRIAN_GREEN:
		onGreenPedes();
		buzzer_on();
		if (status==AUTO_AMBER_RED) {
			status_pedestrian=1000;
			buzzer_off();
			setTimer(5, 100);
		}
//		if (timerFlag[5]==1) {
//			status_pedestrian=PEDESTRIAN_AMBER;
//			setTimer(5, realAmberTime*100);
//		}
		break;
	case PEDESTRIAN_RED:
		onRedPedes();
		if (status==AUTO_GREEN_RED) {
			status_pedestrian=PEDESTRIAN_GREEN;
			b=1;
		}
		break;
	case 1000:
		onRedPedes();
		if (timerFlag[5]) {
			status_pedestrian=2000;
		}
	default:
		clearPedesLed();
		break;
	}
}
