#include "HD44780.h"
#include "HD44780_config.h"

static void LCD_write4(uint8_t cmd) {
    LCD_PIN_WRITE(HD44780_EN_DR, HD44780_EN, 1);
    LCD_PIN_WRITE(HD44780_D7_DR, HD44780_D7, cmd & (1 << 3));
    LCD_PIN_WRITE(HD44780_D6_DR, HD44780_D6, cmd & (1 << 2));
    LCD_PIN_WRITE(HD44780_D5_DR, HD44780_D5, cmd & (1 << 1));
    LCD_PIN_WRITE(HD44780_D4_DR, HD44780_D4, cmd & (1 << 0));
    LCD_PIN_WRITE(HD44780_EN_DR, HD44780_EN, 0);
    LCD_delay_ms(10);
}

static void LCD_write(uint8_t cmd) {
    LCD_write4(cmd >> 4);
    LCD_write4(cmd & 0x0f);
}

void LCD_putc(char c) {
    LCD_PIN_WRITE(HD44780_RS_DR, HD44780_RS, 1);
    LCD_write(c);
}

void LCD_cmd(uint8_t cmd) {
    LCD_PIN_WRITE(HD44780_RS_DR, HD44780_RS, 0);
    LCD_write(cmd);
}

void LCD_goto(uint8_t col, uint8_t row) {
    LCD_PIN_WRITE(HD44780_RS_DR, HD44780_RS, 0);
    if (row == 0)
        LCD_write(0x80 + col);
    else
        LCD_write(0xC0 + col);
}

void LCD_init(void) {
    LCD_gpio_init();
    LCD_PIN_WRITE(HD44780_RS_DR, HD44780_RS, 0);
    LCD_PIN_WRITE(HD44780_EN_DR, HD44780_EN, 0);
    LCD_delay_ms(100);

    /* reset sequence */
    for (int i = 0; i < 3; i++) {
        LCD_write4(0x03);
        LCD_delay_ms(5);
    }

    /* LCD initialization */
    LCD_write4(0x02); // 4-bit mode
    LCD_delay_ms(20);
    LCD_write(0x28); // 2-line mode
    LCD_write(0x08); // off
    LCD_write(0x01); // clear
    LCD_write(0x06); // entry mode
    LCD_write(0x0C); // on
}
