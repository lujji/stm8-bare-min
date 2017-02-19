/*
 * LCD_Protocol.h
 *
 * Created: 4/11/2013 3:51:18 PM
 * Author: lujji
 */

#ifndef LCD_H_
#define LCD_H_

#include <stdint.h>
#include "stm8s.h"
#include "spi.h"
#include "delay.h"

/* LCD connection:
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

/* Pin configuration */
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

/* Platform-specific functions */
static inline void LCD_SPI_write(uint8_t word) {
    SPI_write(word);
}

static inline void LCD_delay_ms(int ms) {
    delay_ms(ms);
}

/* LCD functions */
void LCD_write(uint8_t data);

/*
 * Initialize LCD and corresponding IO pins
 */
void LCD_init();

/*
 * Clear display
 */
void LCD_clear();

/*
 * Send command to display
 */
void LCD_cmd(uint8_t command);

/*
 * col: 0 .. 83
 * row: 0 .. 5
 */
void LCD_goto(uint8_t x, uint8_t y);

/*
 * Write char to display
 */
void LCD_putc(char c);

#endif /* LCD_H_ */
