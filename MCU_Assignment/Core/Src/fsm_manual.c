/*
 * fsm_manual.c
 *
 *  Created on: Nov 24, 2023
 *      Author: PC
 */

#include "fsm_manual.h"

void manual_fsm_run(){
	switch(status){
	case MANUAL_GREEN_RED:
		onGreen1();
		onRed2();
		if(isButtonPressed(0)){
			status = TUNING_RED;
			clearled();
			setTimer(3, 50);
		}
		if(isButtonPressed(1)){
			status = MANUAL_AMBER_RED;
			clearled();
		}

		break;
	case MANUAL_AMBER_RED:
		onAmber1();
		onRed2();
		if(isButtonPressed(0)){
			status = TUNING_RED;
			clearled();
			setTimer(3, 50);
		}
		if(isButtonPressed(1)){
			status = MANUAL_RED_GREEN;
			clearled();
		}
		break;
	case MANUAL_RED_GREEN:
		onRed1();
		onGreen2();
		if(isButtonPressed(0)){
			status = TUNING_RED;
			clearled();
			setTimer(3, 50);
		}
		if(isButtonPressed(1)){
			status = MANUAL_RED_AMBER;
			clearled();
		}
		break;
	case MANUAL_RED_AMBER:
		onRed1();
		onAmber2();
		if(isButtonPressed(0)){
			status = TUNING_RED;
			clearled();
			setTimer(3, 50);
		}
		if(isButtonPressed(1)){
			status = MANUAL_GREEN_RED;
			clearled();
		}
		break;
	default:
		break;
	}
}


