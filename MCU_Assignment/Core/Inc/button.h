/*
 * button.h
 *
 *  Created on: Nov 16, 2023
 *      Author: HOME
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define MAX_BUTTON 3
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
#define GPIO_PIN_(port, pin) (port, ((uint16_t)(1 << (pin))))

extern uint16_t buttonPin[MAX_BUTTON];
extern int button_flag[MAX_BUTTON];
extern int timerForKeyPress;

void subKeyProcess(int index);
void getKeyInput();
int isButtonPressed(int index);


#endif /* INC_BUTTON_H_ */
