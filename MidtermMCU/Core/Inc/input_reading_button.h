/*
 * input_reading.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#ifndef INC_INPUT_READING_BUTTON_H_
#define INC_INPUT_READING_BUTTON_H_

#include "main.h"

#define N0_OF_BUTTONS					   3

#define BUTTONPORT 						   GPIOA

#define DURATION_FOR_AUTO_INCREASING	   300

void button_reading(void);
unsigned char isbuttonpressed(unsigned char index);
unsigned char isbuttonpressed3s(unsigned char index);


#endif /* INC_INPUT_READING_BUTTON_H_ */
