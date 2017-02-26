#include "LCD.h"
#include "LCD_config.h"
#include "font_5x8.h"

#define FONT_WIDTH 5

void LCD_init() {
    LCD_gpio_init();
    LCD_CE_clear();
    LCD_RST_clear();
    LCD_delay_ms(50);
    LCD_RST_set();
    LCD_CE_set();
    LCD_cmd(0x21); // extended commands
    LCD_cmd(0xc0); // contrast Vop=6.4V
    LCD_cmd(0x04); // temperature coefficient
    LCD_cmd(0x13); // bias = 1:48

    LCD_cmd(0x20); // standard commands
    LCD_cmd(0x0C); // normal mode

    LCD_clear();
}

void LCD_cmd(uint8_t cmd) {
    LCD_CE_clear();
    LCD_DC_clear();
    LCD_SPI_write(cmd);
    LCD_CE_set();
}

void LCD_write(uint8_t data) {
    LCD_CE_clear();
    LCD_DC_set();
    LCD_SPI_write(data);
    LCD_CE_set();
}

void LCD_clear() {
    uint16_t i = 84 * 6;
    LCD_goto(0, 0);
    while (i-- > 0)
        LCD_write(0);
}

void LCD_goto(uint8_t col, uint8_t row) {
    LCD_cmd(0x80 | col);
    LCD_cmd(0x40 | row);
}

void LCD_putc(char c) {
    if (c == ' ') {
        LCD_write(0);
        LCD_write(0);
    } else {
        const char *ptr = &font[(c - 32) * FONT_WIDTH];
        for (uint8_t i = 0; i < FONT_WIDTH; i++, ptr++)
            if (*ptr)
                LCD_write(*ptr);
        LCD_write(0);
    }
}
