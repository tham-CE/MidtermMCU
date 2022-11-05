/*
 * led7_display.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */
#include "led7_display.h"

void display7SEG(uint8_t num)
{
	HAL_GPIO_WritePin(PORT7SEG, a_Pin|b_Pin|c_Pin|d_Pin|e_Pin|f_Pin|g_Pin, RESET);
	switch (num)
		{
		case 0:
			HAL_GPIO_WritePin(PORT7SEG, g_Pin ,SET);
			break;
		case 1:
			HAL_GPIO_WritePin(PORT7SEG, a_Pin|d_Pin|e_Pin|f_Pin|g_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(PORT7SEG, f_Pin|c_Pin, SET);
			break;
		case 3:
			HAL_GPIO_WritePin(PORT7SEG, f_Pin|e_Pin, SET);
			break;
		case 4:
			HAL_GPIO_WritePin(PORT7SEG, e_Pin|d_Pin|a_Pin, SET);
			break;
		case 5:
			HAL_GPIO_WritePin(PORT7SEG, e_Pin|b_Pin, SET);
			break;
		case 6:
			HAL_GPIO_WritePin(PORT7SEG, b_Pin ,SET);
			break;
		case 7:
			HAL_GPIO_WritePin(PORT7SEG, d_Pin|e_Pin|f_Pin|g_Pin, SET);
			break;
		case 8:
			break;
		case 9:
			HAL_GPIO_WritePin(PORT7SEG, e_Pin ,SET);
			break;
		}
}

