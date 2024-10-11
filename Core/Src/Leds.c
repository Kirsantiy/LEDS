/*
 * Leds.c
 *
 *  Created on: 11 окт. 2024 г.
 *      Author: Kirs
 */

#include "Leds.h"

void led_init(volatile LEDS *led, uint16_t timer_frequency,
		uint16_t led_frequency, uint16_t blink_time) {
	led->timer_frequency = timer_frequency;
	led->led_frequency = led_frequency;
	led->blink_time = blink_time;
	led->is_on = 0;

}

uint16_t set_led_frequency(volatile LEDS *led) {
	return (led->timer_frequency / led->led_frequency);
	// Суть в получении количества тактов таймера, которое будет характеризовать одно мигание светодиода, будет выступать как значение counter
}

uint16_t set_blink_time(volatile LEDS *led) {
	return (led->blink_time * led->timer_frequency);
	// Здесь мы домножаем полученное количество секунд на частоту, чтобы определить количество тактов, требуемых для отключения, идет как значение counter_stop
}

void blink_start(volatile LEDS *led) {
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
}

void blink_stop(volatile LEDS *led) {
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
}

/*uint8_t button_stop(volatile LEDS *led) {
	if (HAL_GPIO_ReadPin(GPIOx, GPIO_PIN_x) == GPIO_PIN_RESET) { // Если кнопка нажата, здесь нужно указать номер пина, к которому подключена кнопка
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
	}
	return 1;
}*/
