/*
 * display_7_segment.c
 *
 *  Created on: Nov 9, 2021
 *      Author: Quan Nguyen
 */

#include "main.h"
#include "display_7_segment.h"

void displaySegment(uint8_t num, uint8_t low) {
	if (low) {
		GPIOA->ODR &= CLEAR_LOW;
		switch (num) {
			case 0:
				GPIOA->ODR |= (ZERO_DISPLAY << LOW_BIT_OFFSET);
				break;
			case 1:
				GPIOA->ODR |= (ONE_DISPLAY << LOW_BIT_OFFSET);
				break;
			case 2:
				GPIOA->ODR |= (TWO_DISPLAY << LOW_BIT_OFFSET);
				break;
			case 3:
				GPIOA->ODR |= (THREE_DISPLAY << LOW_BIT_OFFSET);
				break;
			case 4:
				GPIOA->ODR |= (FOUR_DISPLAY << LOW_BIT_OFFSET);
				break;
			case 5:
				GPIOA->ODR |= (FIVE_DISPLAY << LOW_BIT_OFFSET);
				break;
			case 6:
				GPIOA->ODR |= (SIX_DISPLAY << LOW_BIT_OFFSET);
				break;
			case 7:
				GPIOA->ODR |= (SEVEN_DISPLAY << LOW_BIT_OFFSET);
				break;
			case 8:
				GPIOA->ODR |= (EIGTH_DISPLAY << LOW_BIT_OFFSET);
				break;
			case 9:
				GPIOA->ODR |= (NINE_DISPLAY << LOW_BIT_OFFSET);
				break;
		}
	} else {
		GPIOA->ODR &= CLEAR_HIGH;
		switch (num) {
			case 0:
				GPIOA->ODR |= (ZERO_DISPLAY << HIGH_BIT_OFFSET);
				break;
			case 1:
				GPIOA->ODR |= (ONE_DISPLAY << HIGH_BIT_OFFSET);
				break;
			case 2:
				GPIOA->ODR |= (TWO_DISPLAY << HIGH_BIT_OFFSET);
				break;
			case 3:
				GPIOA->ODR |= (THREE_DISPLAY << HIGH_BIT_OFFSET);
				break;
			case 4:
				GPIOA->ODR |= (FOUR_DISPLAY << HIGH_BIT_OFFSET);
				break;
			case 5:
				GPIOA->ODR |= (FIVE_DISPLAY << HIGH_BIT_OFFSET);
				break;
			case 6:
				GPIOA->ODR |= (SIX_DISPLAY << HIGH_BIT_OFFSET);
				break;
			case 7:
				GPIOA->ODR |= (SEVEN_DISPLAY << HIGH_BIT_OFFSET);
				break;
			case 8:
				GPIOA->ODR |= (EIGTH_DISPLAY << HIGH_BIT_OFFSET);
				break;
			case 9:
				GPIOA->ODR |= (NINE_DISPLAY << HIGH_BIT_OFFSET);
				break;
		}
	}
}
void updateSegment(uint8_t index) {
	switch (index) {
	case 0:
		HAL_GPIO_WritePin(ENB_GPIO_Port, ENB_Pin, GPIO_PIN_SET);
		displaySegment(led_buffer_0[0], 0);
		displaySegment(led_buffer_1[0], 1);
		HAL_GPIO_WritePin(ENA_GPIO_Port, ENA_Pin, GPIO_PIN_RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(ENA_GPIO_Port, ENA_Pin, GPIO_PIN_SET);
		displaySegment(led_buffer_0[1], 0);
		displaySegment(led_buffer_1[1], 1);
		HAL_GPIO_WritePin(ENB_GPIO_Port, ENB_Pin, GPIO_PIN_RESET);
	}
}
