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

/*
 * timer0: for fsm automatic led
 * timer1: update 7 segments led buffer
 * timer2: update 7 segments led
 * timer3: blinky led fsm tunning mode
 * timer3:
 * timer5:
 * timer6:
 * timer7:
 * timer8:
 * timer9: uart
 */
void setTimer(uint8_t index, uint16_t duration);
void timerRun(uint8_t index);
void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
