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


#define MAN_RED 21
#define MAN_AMBER 22
#define MAN_GREEN 23
extern int status;


#endif /* INC_GLOBAL_H_ */