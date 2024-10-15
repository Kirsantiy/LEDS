#include "Leds.h"

void led_init(volatile LEDS *led, uint16_t timer_frequency,
		uint16_t led_frequency, uint16_t blink_time) {
	led->timer_frequency = timer_frequency;
	led->led_frequency = led_frequency;
	led->blink_time = blink_time;
	led->is_on = 0;
	led->counter = 0;
	led->counter_max = 0;
}

void leds_calculation(volatile LEDS *led) {
	led->counter++;
	led->counter_max++;

	led->trigger_time = led->timer_frequency / (led->led_frequency * 2);

	if (led->counter_max >= (led->blink_time * led->timer_frequency)) {
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 1);
	}
	else if (led->counter <= led->trigger_time) {
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, led->is_on);
		if(led->counter == led->trigger_time) {
			led->is_on = !led->is_on;
			led->counter = 0;
		}
	}
}
