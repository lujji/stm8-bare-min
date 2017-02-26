#include "uart.h"
#include "stm8s.h"

/*
 * PD5 -> CN4.10 (TX)
 * PD6 -> CN4.11 (RX)
 */
void uart_init() {
    // 2000000/9600 = 208 (0xD0)
    UART1_BRR1 = 0x0D;
    UART1_BRR2 = 0x00;
    UART1_CR2 = (1 << UART1_CR2_TEN) | (1 << UART1_CR2_REN);
}

void uart_write(uint8_t data) {
    UART1_DR = data;
    while (!(UART1_SR & (1 << UART1_SR_TC)));
}

uint8_t uart_read() {
    while (!(UART1_SR & (1 << UART1_SR_RXNE)));
    return UART1_DR;
}
