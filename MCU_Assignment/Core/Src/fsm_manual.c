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
			uart_communication_fsm();
		}
		if(isButtonPressed(1)){
			status = MANUAL_AMBER_RED;
			clearled();
			uart_communication_fsm();
		}

		break;
	case MANUAL_AMBER_RED:
		onAmber1();
		onRed2();
		if(isButtonPressed(0)){
			status = TUNING_RED;
			clearled();
			setTimer(3, 50);
			uart_communication_fsm();
		}
		if(isButtonPressed(1)){
			status = MANUAL_RED_GREEN;
			clearled();
			uart_communication_fsm();
		}
		break;
	case MANUAL_RED_GREEN:
		onRed1();
		onGreen2();
		if(isButtonPressed(0)){
			status = TUNING_RED;
			clearled();
			setTimer(3, 50);
			uart_communication_fsm();
		}
		if(isButtonPressed(1)){
			status = MANUAL_RED_AMBER;
			clearled();
			uart_communication_fsm();
		}
		break;
	case MANUAL_RED_AMBER:
		onRed1();
		onAmber2();
		if(isButtonPressed(0)){
			status = TUNING_RED;
			clearled();
			setTimer(3, 50);
			uart_communication_fsm();
		}
		if(isButtonPressed(1)){
			status = MANUAL_GREEN_RED;
			clearled();
			uart_communication_fsm();
		}
		break;
	default:
		break;
	}
}


