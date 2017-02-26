#ifndef LCD_H
#define LCD_H

#include <stdint.h>
#include <stm8s.h>

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

/*
 * Write byte to display
 */
void LCD_write(uint8_t data);

#endif /* LCD_H */
