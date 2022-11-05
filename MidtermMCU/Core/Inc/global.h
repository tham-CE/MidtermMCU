/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

#define BUTTON1		0
#define BUTTON2		1
#define BUTTON3		2

#define TIME_UNIT 10000

//Number of timer
#define TIMER_INTERRUPT 10

extern uint8_t saveVal;
extern uint8_t number;

extern uint8_t IncreaseNumberM1;
extern uint8_t DecreaseNumberM1;

extern uint8_t DecreaseNumberM2;

void Init(void);

#endif /* INC_GLOBAL_H_ */
