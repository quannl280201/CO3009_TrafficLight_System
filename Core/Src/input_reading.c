/*
 * input_reading.c
 *
 *  Created on: Nov 9, 2021
 *      Author: Quan Nguyen
 */
#include "main.h"
#include "input_reading.h"

//the buffer that the final result is stored after
//debouncing
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];
//we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];
//we define a flag for a button pressed more than 1 second.
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];
//we define counter for automatically increasing the value
//after the button is pressed more than 1 second.
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];
GPIO_TypeDef* buttonPortArray[N0_OF_BUTTONS] = {BUTTON_MODE_GPIO_Port, BUTTON_TIME_GPIO_Port, BUTTON_SET_GPIO_Port};
uint16_t buttonPinArray[N0_OF_BUTTONS] = {BUTTON_MODE_Pin, BUTTON_TIME_Pin, BUTTON_SET_Pin};
void button_reading(void){
	for(int i = 0; i < N0_OF_BUTTONS; i ++){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(buttonPortArray[i], buttonPinArray[i]);
		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){
			buttonBuffer[i] = debounceButtonBuffer1[i];
			if(buttonBuffer[i] == BUTTON_IS_PRESSED){
			//if a button is pressed, we start counting
				if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING){
					counterForButtonPress1s[i]++;
				} else {
				//the flag is turned on when 1 second has passed
				//since the button is pressed.
					flagForButtonPress1s[i] = 1;
				}
			} else {
				counterForButtonPress1s[i] = 0;
				flagForButtonPress1s[i] = 0;
			}
		}
	}
}
unsigned char is_button_pressed(unsigned char index){
	return buttonBuffer[index];
}
unsigned char is_button_pressed_1s(unsigned char index){
	return flagForButtonPress1s[index];
}


