/*
 * SoftwareTimer.h
 *
 *  Created on: Nov 9, 2021
 *      Author: Quan Nguyen
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

#define TRUE 1
#define FALSE 0
#define NUM_OF_TIMERS 3
#define SYS_TIMER_CYCLE 10

typedef uint32_t TIME;
typedef struct SoftTimer SoftTimer;

struct SoftTimer{
	uint8_t inuse;
	TIME time;
	uint8_t flag;
}timer_array[NUM_OF_TIMERS];

void initTimer();
void setTimer(uint8_t timer_use,TIME duration);
void runTimer();

#endif /* INC_SOFTWARETIMER_H_ */
