/*
 * SoftwareTimer.c
 *
 *  Created on: Nov 9, 2021
 *      Author: Quan Nguyen
 */
#include "main.h"
#include "SoftwareTimer.h"

void initTimer(){
	uint8_t i;
	for(i = 0; i < NUM_OF_TIMERS; i++){
		timer_array[i].inuse = FALSE;
		timer_array[i].flag = FALSE;
		timer_array[i].time = 0;
	}
}
void setTimer(uint8_t timer_use,TIME duration){
	if(timer_use >= 0 && timer_use < NUM_OF_TIMERS){
		timer_array[timer_use].inuse = TRUE;
		timer_array[timer_use].time = duration / SYS_TIMER_CYCLE;
		timer_array[timer_use].flag = FALSE;
	}
}
void runTimer(){
	uint8_t i;
	for(i = 0; i < NUM_OF_TIMERS; i++){
		if(timer_array[i].inuse){
			if(timer_array[i].time > 0){
				timer_array[i].time--;
				if(timer_array[i].time == 0)
					timer_array[i].flag = TRUE;
			}
		}
	}
}

