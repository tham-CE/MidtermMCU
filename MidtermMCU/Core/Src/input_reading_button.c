/*
 * input_reading.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#include "input_reading_button.h"
#include "main.h"



#define PRESSED_STATE                GPIO_PIN_RESET
#define NORMAL_STATE                 GPIO_PIN_SET

uint16_t buttonPin[3] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};

static GPIO_PinState buttonBuffer[N0_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};


static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];


static uint8_t flagForButtonPress3s[N0_OF_BUTTONS];
static uint16_t counterForButtonPress3s[N0_OF_BUTTONS];

void button_reading(void){
	for(uint8_t i = 0; i < N0_OF_BUTTONS; i ++){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTONPORT, buttonPin[i]);

		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
			buttonBuffer[i] = debounceButtonBuffer1[i];
		if(buttonBuffer[i] == PRESSED_STATE)
		{
			// if a button is pressed , we start counting
			if(counterForButtonPress3s[i] < DURATION_FOR_AUTO_INCREASING)
			{
				counterForButtonPress3s[i]++;
			}
			else
			{
				// the flag is turned on when 1 second has passed
				// since the button is pressed
				flagForButtonPress3s[i] = 1;
				// todo
			}
		}
		else
		{
			counterForButtonPress3s[i] = 0;
			flagForButtonPress3s[i] = 0;
		}
	}
}


unsigned char isbuttonpressed (uint8_t index){
	if(index >= N0_OF_BUTTONS) return 0;

	if(buttonBuffer[index] == PRESSED_STATE){
		return (counterForButtonPress3s[index] == 1);
	}
	return 0;
}

unsigned char isbuttonpressed3s (unsigned char index ) {
if( index >= N0_OF_BUTTONS ) return 0xff;
return ( flagForButtonPress3s [ index ] == 1) ;
}
