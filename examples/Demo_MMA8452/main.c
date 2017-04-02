#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stm8s.h>
#include <i2c.h>
#include <delay.h>
#include "HD44780.h"
#include "MMA8452.h"

#ifndef PI
#define PI   3.1415927
#endif

#define TAG  "Tilt: "

char txt[16] = TAG;

/**
 * In-place itoa.
 *
 * @param n integer to convert
 * @param buf destination buffer
 * @return pointer to string end
 */
char *itoa_i(int n, char *buf) {
    char *ret, *end = buf;
    do *(end++) = '0' + n % 10; while (n /= 10);
    /* reverse string */
    ret = end--;
    for (char *ptr = buf; ptr < end; ptr++, end--) {
        char tmp = *ptr;
        *ptr = *end;
        *end = tmp;
    }
    return ret;
}

void angle_to_str(int n, char *tag) {
    char *tag_end = tag + 5;

    tag = itoa_i(n, tag);
    *(tag++) = 0xDF; // degree

    /* pad with whitespaces */
    for (; tag < tag_end; tag++)
        *tag = ' ';

    /* null-terminate */
    *tag = '\0';
}

void LCD_puts(char *str) {
    while (*str)
        LCD_putc(*str++);
}

void main() {
    LCD_init();
    i2c_init();
    MMA8452_init();

    while (1) {
        float angle;
        int16_t x, y, z;
        MMA8452_readXYZ(&x, &y, &z);

        /* we need to downscale to do the math.. */
        x /= 50;
        y /= 50;
        z /= 50;
        angle = acosf((y / sqrtf(x * x + y * y + z * z))) * (180.0 / PI);

        LCD_goto(0, 0);
        angle_to_str((uint16_t) angle, &txt[sizeof(TAG) - 1]);
        LCD_puts(txt);

        delay_ms(50);
    }
}
