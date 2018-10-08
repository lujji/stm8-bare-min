/*
 * LCD driver platform-specific configuration.
 * This file should not be included directly.
 */
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#include <stdint.h>
#include <stm8s.h>
#include <spi.h>
#include <delay.h>

/*
 * LCD connection:
 *
 * 1 RST -> PC3
 * 2 CE  -> PC4
 * 3 DC  -> PD2
 * 4 DIN -> PC6
 * 5 CLK -> PC5
 * 6 VCC
 * 7 LED -> GND
 * 8 GND
 */

#define LCD_DC_PIN      2       // data/command mode
#define LCD_CE_PIN      4       // chip-select
#define LCD_RST_PIN     3       // reset

static inline void LCD_gpio_init() {
    PC_DDR |= (1 << LCD_CE_PIN) | (1 << LCD_RST_PIN);
    PC_CR1 |= (1 << LCD_CE_PIN) | (1 << LCD_RST_PIN);
    PD_DDR |= (1 << LCD_DC_PIN);
    PD_CR1 |= (1 << LCD_DC_PIN);
}

static inline void LCD_DC_set() {
    PD_ODR |= (1 << LCD_DC_PIN);
}

static inline void LCD_DC_clear() {
    PD_ODR &= ~(1 << LCD_DC_PIN);
}

static inline void LCD_CE_set() {
    while ((SPI_SR & (1 << SPI_SR_BSY)));
    PC_ODR |= (1 << LCD_CE_PIN);
}

static inline void LCD_CE_clear() {
    PC_ODR &= ~(1 << LCD_CE_PIN);
}

static inline void LCD_RST_set() {
    PC_ODR |= (1 << LCD_RST_PIN);
}

static inline void LCD_RST_clear() {
    PC_ODR &= ~(1 << LCD_RST_PIN);
}

static inline void LCD_SPI_write(uint8_t word) {
    SPI_write(word);
}

static inline void LCD_delay_ms(int ms) {
    delay_ms(ms);
}

#endif /* LCD_CONFIG_H */
