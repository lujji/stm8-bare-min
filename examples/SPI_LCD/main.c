#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stm8s.h>
#include <delay.h>
#include <spi.h>
#include "LCD.h"
#include "sprites.h"

const char text[] = "HELLO, WORLD!";

void LCD_draw_sprite(const unsigned char *sprite) {
    uint16_t i = 84 * 6;
    LCD_goto(0, 0);
    while (i-- > 0)
        LCD_write(*(sprite++));
}

void main() {
    SPI_init();
    LCD_init();

    LCD_goto(12, 2);
    for (int i = 0; i < sizeof(text) - 1; i++)
        LCD_putc(text[i]);
    delay_ms(2000);

    while (1) {
        LCD_draw_sprite(sprite0);
        delay_ms(1500);
        LCD_draw_sprite(sprite1);
        delay_ms(1500);
    }
}
