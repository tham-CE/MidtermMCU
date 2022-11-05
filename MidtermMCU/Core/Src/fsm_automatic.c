/*
 * fsm_automatic.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */
#include "fsm_automatic.h"
#include "global.h"

enum MODE {MODE0, MODE1, MODE2};

enum MODE mode = MODE0;

uint16_t TimeOut = TIME_UNIT / TIMER_INTERRUPT;

void Mode0()
{
	if(isbuttonpressed(BUTTON1))
	{
		TimeOut = TIME_UNIT / TIMER_INTERRUPT;
		number = 0;
	}
	else if(isbuttonpressed(BUTTON2))
	{
		TimeOut = TIME_UNIT / TIMER_INTERRUPT;
		number = number + 1 > 9 ? 0 : number + 1;
	}
	else if(isbuttonpressed(BUTTON3))
	{
		TimeOut = TIME_UNIT / TIMER_INTERRUPT;
		number = number - 1 < 0 ? 9 : number - 1;
	}
}

void fsm_simple_buttons_run()
{
	switch(mode)
	{
	case MODE0:
		Mode0();
		if(isbuttonpressed3s(BUTTON2) || isbuttonpressed3s(BUTTON3))
		{
			mode = MODE1;
		}
		if(TimeOut == 0)
		{
			saveVal = number;
			mode = MODE2;
		}
		TimeOut--;
		break;
	case MODE1:
		if(isbuttonpressed3s(BUTTON2))
		{
			IncreaseNumberM1 = 1;
		}
		else if(isbuttonpressed3s(BUTTON3))
		{
			DecreaseNumberM1 = 1;
		}
		else
		{
			IncreaseNumberM1 = 0;
			DecreaseNumberM1 = 0;
			mode = MODE0;
		}
		break;
	case MODE2:
		DecreaseNumberM2 = 1;
		if(isbuttonpressed(BUTTON2) || isbuttonpressed(BUTTON3))
		{
			DecreaseNumberM2 = 0;
			number = saveVal;
			mode = MODE0;
		}
		break;
	default:
		break;
	}
}
