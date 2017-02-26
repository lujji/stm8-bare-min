/*
 * LCD driver platform-specific configuration.
 * This file should not be included directly.
 */
#ifndef HD44780_CONFIG_H
#define HD44780_CONFIG_H

#include <stm8s.h>
#include <delay.h>

/*
 * LCD connection:
 *
 * RS -> PC6
 * RW -> GND
 * EN -> PC5
 * D4 -> PD3
 * D5 -> PD2
 * D6 -> PD1
 * D7 -> PC7
 */
#define HD44780_D4_DR       PD_ODR
#define HD44780_D4          3
#define HD44780_D5_DR       PD_ODR
#define HD44780_D5          2
#define HD44780_D6_DR       PD_ODR
#define HD44780_D6          1
#define HD44780_D7_DR       PC_ODR
#define HD44780_D7          7
#define HD44780_RS_DR       PC_ODR
#define HD44780_RS          6
#define HD44780_EN_DR       PC_ODR
#define HD44780_EN          5

#define LCD_PIN_WRITE(ODR, PIN, STATE) ((STATE) ? (ODR |= (1 << PIN)) : (ODR &= ~(1 << PIN)))

static inline void LCD_gpio_init() {
    /* note: this relies on DDR and CR1 registers memory offset */
    *(&HD44780_D4_DR + 2) |= (1 << HD44780_D4);
    *(&HD44780_D4_DR + 3) |= (1 << HD44780_D4);

    *(&HD44780_D5_DR + 2) |= (1 << HD44780_D5);
    *(&HD44780_D5_DR + 3) |= (1 << HD44780_D5);

    *(&HD44780_D6_DR + 2) |= (1 << HD44780_D6);
    *(&HD44780_D6_DR + 3) |= (1 << HD44780_D6);

    *(&HD44780_D7_DR + 2) |= (1 << HD44780_D7);
    *(&HD44780_D7_DR + 3) |= (1 << HD44780_D7);

    *(&HD44780_EN_DR + 2) |= (1 << HD44780_EN);
    *(&HD44780_EN_DR + 3) |= (1 << HD44780_EN);

    *(&HD44780_RS_DR + 2) |= (1 << HD44780_RS);
    *(&HD44780_RS_DR + 3) |= (1 << HD44780_RS);
}

static inline void LCD_delay_ms(uint8_t ms) {
    delay_ms(ms);
}

#endif /* HD44780_CONFIG_H */
