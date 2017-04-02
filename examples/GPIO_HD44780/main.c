#include <stdio.h>
#include <string.h>
#include <stm8s.h>
#include <delay.h>
#include "HD44780.h"

/*
 * Redirect stdout to LCD
 */
int putchar(int c) {
    LCD_putc(c);
    return 0;
}

void main() {
    uint8_t counter = 0;

    LCD_init();
    LCD_goto(1, 0);
    printf("Hello,  World!");
    delay_ms(2000);
    LCD_cmd(HD44780_CMD_CLEAR);

    while (1) {
        LCD_goto(1, 0);
        printf("Count: %d  ", counter++);
        delay_ms(250);
    }
}
