/*
 *  LED -- simple LED support
 */

#ifndef __LED_h
#define __LED_h

#define __LONG_LED

#include <stdio.h>


#include <bsp/io.h> //Everything we need is in io.h

//STM32F4 Discovery Board, LED4: PORTD, 12
stm32f4_gpio_config led3config =
{
	.fields={
		.pin_first = STM32F4_GPIO_PIN(6, 10),
	.pin_last = STM32F4_GPIO_PIN(6, 10),
	.mode = STM32F4_GPIO_MODE_OUTPUT,
	.otype = STM32F4_GPIO_OTYPE_PUSH_PULL,
	.ospeed = STM32F4_GPIO_OSPEED_2_MHZ,
	.pupd = STM32F4_GPIO_NO_PULL,
	.output = 1,
	.af = 0
   }
};

#define LED_INIT() stm32f4_gpio_set_config(&led3config)
#define LED_ON() stm32f4_gpio_set_output(STM32F4_GPIO_PIN(6,10), 1)
#define LED_OFF() stm32f4_gpio_set_output(STM32F4_GPIO_PIN(6,10), 0)

#endif
