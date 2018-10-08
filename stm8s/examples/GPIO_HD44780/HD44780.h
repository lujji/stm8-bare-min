#ifndef HD44780_H
#define HD44780_H

#include <stdint.h>
#include <stm8s.h>

#define HD44780_CMD_CLEAR   0x01

/*
 * Initialize LCD and corresponding IO pins
 */
void LCD_init();

/*
 * Write char to display
 */
void LCD_putc(char c);

/*
 * Set LCD cursor
 *
 * @param col: 0 .. 15
 * @param row: 0 .. 1
 */
void LCD_goto(uint8_t col, uint8_t row);

/*
 * Send command to display
 */
void LCD_cmd(uint8_t cmd);

#endif /* HD44780_H */
