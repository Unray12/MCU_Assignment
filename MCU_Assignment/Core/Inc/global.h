/*
 * global.h
 *
 *  Created on: Nov 18, 2023
 *      Author: HOME
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
#include"myLib.h"


#define INIT 1
#define AUTO_RED_GREEN 2
#define AUTO_RED_AMBER 3
#define AUTO_GREEN_RED 4
#define AUTO_AMBER_RED 5

#define PEDESTRIAN		10
#define PEDESTRIAN_RED 11
#define PEDESTRIAN_AMBER 12
#define PEDESTRIAN_GREEN 13

#define TUNING_RED 21
#define TUNING_AMBER 22
#define TUNING_GREEN 23

#define MANUAL_RED_GREEN 26
#define MANUAL_RED_AMBER 27
#define MANUAL_GREEN_RED 28
#define MANUAL_AMBER_RED 29

extern int status;
extern int status_pedestrian;
extern int buzzer_flag;
extern int b;

#endif /* INC_GLOBAL_H_ */
