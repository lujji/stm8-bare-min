#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stm8s.h>
#include <uart.h>
#include <delay.h>

/*
 * Redirect stdout to UART
 */
int putchar(int c) {
    uart_write(c);
    return 0;
}

/*
 * Redirect stdin to UART
 */
char getchar() {
    return uart_read();
}

int main() {
    uint8_t counter = 0;
    uart_init();

    while (1) {
        printf("Test, %d\n", counter++);
        delay_ms(500);
    }
}
