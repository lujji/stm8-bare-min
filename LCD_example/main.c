#include <stdio.h>
#include <string.h>
#include <math.h>

#include "stm8s.h"
#include "delay.h"
#include "spi.h"
#include "LCD.h"

const char text[] = "Hello, World!";

int main() {
    SPI_init();
    LCD_init();

    LCD_goto(0, 0);
    for (int i = 0; i < sizeof(text) - 1; i++)
        LCD_putc(text[i]);

    while (1) {

    }
}
