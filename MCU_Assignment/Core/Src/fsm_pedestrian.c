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
//		setTimer(5, realGreenTime);
//		timerFlag[3]=0;
//	}
	switch(status_pedestrian) {
	case PEDESTRIAN:
//		HAL_GPIO_TogglePin(D2_GPIO_Port,D2_Pin);
		buzzer_on();
		break;
	case PEDESTRIAN_GREEN:
		onGreenPedes();
		if (timerFlag[5]==1) {
			setTimer(5, realAmberTime);
			status_pedestrian=PEDESTRIAN_AMBER;
			timerFlag[5]=0;
		}
		break;
	case PEDESTRIAN_AMBER:
		onAmberPedes();
		if (timerFlag[5]==1) {
			status_pedestrian=1000;
			timerFlag[5]=0;
		}
		break;
	default:
		onRedPedes();
		break;
	}
}
