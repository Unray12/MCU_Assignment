/*
 * button.c
 *
 *  Created on: Nov 16, 2023
 *      Author: HOME
 */

#include "button.h"

struct buttonPinPair {
	GPIO_TypeDef* GPIOtype;
	uint16_t buttonPin;
};

struct buttonPinPair button_pin[MAX_BUTTON] = {
		{GPIOA, GPIO_PIN_(1)},
		{GPIOA, GPIO_PIN_(4)},
		{GPIOB, GPIO_PIN_(0)},
		{GPIOA, GPIO_PIN_(0)}
};

int keyReg0[MAX_BUTTON] = {NORMAL_STATE};
int keyReg1[MAX_BUTTON] = {NORMAL_STATE};
int keyReg2[MAX_BUTTON] = {NORMAL_STATE};

int keyReg3[MAX_BUTTON] = {NORMAL_STATE};
int timerForKeyPress[MAX_BUTTON] = {200};
int button_flag[MAX_BUTTON] = {0};

int isButtonPressed(int index) {
	if(button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index) {
	button_flag[index] = 1;
}


void getKeyInput(int index) {
	keyReg0[index] = keyReg1[index];
	keyReg1[index] = keyReg2[index];

	keyReg2[index] = HAL_GPIO_ReadPin(button_pin[index].GPIOtype, button_pin[index].buttonPin);
	//keyReg2[index] = HAL_GPIO_ReadPin(A2_GPIO_Port,A2_Pin);
	if ((keyReg0[index] == keyReg1[index]) && (keyReg1[index] == keyReg2[index])) {
		if (keyReg3[index] != keyReg2[index]) {
			keyReg3[index] = keyReg2[index];
			if (keyReg2[index] == PRESSED_STATE) {
				subKeyProcess(index);
				timerForKeyPress[index] = 200;
			}
		}
		else {
			timerForKeyPress[index]--;
			if (timerForKeyPress[index] == 0) {
				keyReg3[index] = NORMAL_STATE;
			}
		}
	}
}
