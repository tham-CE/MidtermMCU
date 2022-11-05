/*
 * global.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#include "global.h"

uint8_t saveVal;
uint8_t number;

uint8_t IncreaseNumberM1;
uint8_t DecreaseNumberM1;

uint8_t DecreaseNumberM2;

void Init(void)
{
	saveVal = 0;
	number = 0;

	IncreaseNumberM1 = 0;
	DecreaseNumberM1 = 0;

	DecreaseNumberM2 = 0;
}

