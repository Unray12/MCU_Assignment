/*
 * software_timer.h
 *
 *  Created on: Nov 16, 2023
 *      Author: HOME
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include <stdint.h>

#define MAX_TIMER 10
extern uint8_t timerFlag[MAX_TIMER];

void setTimer(uint8_t index, uint16_t duration);
void timerRun(uint8_t index);

#endif /* INC_SOFTWARE_TIMER_H_ */
