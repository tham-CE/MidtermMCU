/*
 * timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include <input_reading_button.h>
#include "main.h"


void timerRun();
void setTimer1(uint16_t duration);
void setTimer2(uint16_t duration);

uint8_t Timer1_flag (void);
uint8_t Timer2_flag (void);

#endif /* INC_TIMER_H_ */
