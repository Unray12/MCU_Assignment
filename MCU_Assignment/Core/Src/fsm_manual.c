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
		if(isButtonPressed(0)){
			status = TUNING_RED;
			clearled();
		}
		if(isButtonPressed(1)){
			status = MANUAL_AMBER_RED;
			clearled();
		}
		onGreen1();
		onRed2();
		break;
	case MANUAL_AMBER_RED:
		if(isButtonPressed(0)){
			status = TUNING_RED;
			clearled();
		}
		if(isButtonPressed(1)){
			status = MANUAL_RED_GREEN;
			clearled();
		}
		onAmber1();
		onRed2();
		break;
	case MANUAL_RED_GREEN:
		if(isButtonPressed(0)){
			status = TUNING_RED;
			clearled();
		}
		if(isButtonPressed(1)){
			status = MANUAL_RED_AMBER;
			clearled();
		}
		onRed1();
		onGreen2();
		break;
	case MANUAL_RED_AMBER:
		if(isButtonPressed(0)){
			status = TUNING_RED;
			clearled();
		}
		if(isButtonPressed(1)){
			status = MANUAL_GREEN_RED;
			clearled();
		}
		onRed1();
		onAmber2();
		break;
	default:
		break;
	}
}


