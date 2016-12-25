#include "uart.h"
#include "stm8s.h"

/*
 * PD5 -> CN4.10 (TX)
 * PD6 -> CN4.11 (RX)
 */
void uart_init() {
    // 2000000/9600 = 208 (0xD0)
    UART_BRR1 = 0x0D;
    UART_BRR2 = 0x00;
    UART_CR2 = (1 << UART_CR2_TEN) | (1 << UART_CR2_REN);
}

void uart_write(uint8_t data) {
    UART_DR = data;
    while (!(UART_SR & (1 << UART_SR_TC)));
}

uint8_t uart_read() {
    while (!(UART_SR & (1 << UART_SR_RXNE)));
    return UART_DR;
}

int putchar(int c) {
    uart_write(c);
    return 0;
}
