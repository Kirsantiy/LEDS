/*
 * Leds.h
 *
 *  Created on: 11 окт. 2024 г.
 *      Author: Kirs
 */

#ifndef INC_LEDS_H_
#define INC_LEDS_H_

#include "main.h"

typedef struct {

	uint16_t timer_frequency;
	uint16_t led_frequency;
	uint16_t blink_time;
	uint16_t is_on;

} LEDS;

void led_init(volatile LEDS *led, uint16_t, uint16_t, uint16_t);
uint16_t set_led_frequency(volatile LEDS *led);
uint16_t set_blink_time(volatile LEDS *led);
void blink_start(volatile LEDS *led);
void blink_stop(volatile LEDS *led);
uint8_t button_stop(volatile LEDS *led);

#endif /* INC_LEDS_H_ */
