/*
 * button.h
 *
 *  Created on: Nov 16, 2023
 *      Author: HOME
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

/*
 * button0: change mode
 * button3: pedestrian button
 */
#define MAX_BUTTON 4
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
#define GPIO_PIN_(i) ((uint16_t)(1 << (i)))

extern uint16_t buttonPin[MAX_BUTTON];
extern int button_flag[MAX_BUTTON];
extern int timerForKeyPress[MAX_BUTTON];

void subKeyProcess(int index);
void getKeyInput(int index);
int isButtonPressed(int index);


#endif /* INC_BUTTON_H_ */
