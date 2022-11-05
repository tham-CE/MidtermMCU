/*
 * timer.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */
#include "timer.h"
static uint16_t TIME_CYCLE = 10;

static uint8_t	timer1_flag = 0;
static uint8_t  counter1 = 0;

static uint8_t	timer2_flag = 0;
static uint8_t  counter2 = 0;

void setTimer1(uint16_t duration)
{
	counter1 = duration/TIME_CYCLE;
	timer1_flag = 0;
}

void setTimer2(uint16_t duration)
{
	counter2 = duration/TIME_CYCLE;
	timer2_flag = 0;
}

void timerRun()
{
	if(counter1 > 0)
	{
		counter1--;
		if(counter1 == 0)
			timer1_flag = 1;
	}

	if(counter2 > 0)
	{
		counter2--;
		if(counter2 == 0)
		{
			timer2_flag = 1;
		}
	}
}
uint8_t Timer1_flag(void){
	return timer1_flag;
}
uint8_t Timer2_flag(void){
	return timer2_flag;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2) {
		timerRun();
		button_reading();
	}
}
