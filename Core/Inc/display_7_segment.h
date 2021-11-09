/*
 * display_7_segment.h
 *
 *  Created on: Nov 9, 2021
 *      Author: Quan Nguyen
 */

#ifndef INC_DISPLAY_7_SEGMENT_H_
#define INC_DISPLAY_7_SEGMENT_H_

#define NUM_OF_SEGMENT 		2
#define LOW_BIT_OFFSET 		2
#define HIGH_BIT_OFFSET 	9
#define CLEAR_LOW			0xfffffe03
#define CLEAR_HIGH			0xffff01ff
#define ZERO_DISPLAY 		0x40
#define ONE_DISPLAY 		0x79
#define TWO_DISPLAY			0x24
#define THREE_DISPLAY		0x30
#define FOUR_DISPLAY		0x19
#define FIVE_DISPLAY		0x12
#define SIX_DISPLAY			0x02
#define SEVEN_DISPLAY		0x78
#define EIGTH_DISPLAY		0x00
#define NINE_DISPLAY		0x10

static uint8_t led_buffer_0[NUM_OF_SEGMENT] = {3, 0};
static uint8_t led_buffer_1[NUM_OF_SEGMENT] = {0, 6};

void displaySegment(uint8_t num, uint8_t low);
void updateSegment(uint8_t index);

#endif /* INC_DISPLAY_7_SEGMENT_H_ */
