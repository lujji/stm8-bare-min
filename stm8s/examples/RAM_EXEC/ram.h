#ifndef RAM_H
#define RAM_H

#include <stdint.h>

// set pint to toggle
#define LED_DDR  PD_DDR
#define LED_CR1  PD_CR1
#define LED_ODR  PD_ODR
#define LED_PIN  4
/*
#define LED_DDR  PH_DDR
#define LED_CR1  PH_CR1
#define LED_ODR  PH_ODR
#define LED_PIN  2
*/

void ram_blink(uint8_t count);
void ram_uart_puts(uint8_t *str);

#endif /* RAM_H */
