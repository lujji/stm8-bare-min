#ifndef UART_H
#define UART_H

#include <stdint.h>

/**
 * Initialize UART1 at 9600 8-N-1.
 *
 * PD5 -> CN4.10 (TX)
 * PD6 -> CN4.11 (RX)
 *
 */
void uart_init();

void uart_write(uint8_t data);

uint8_t uart_read();

#endif /* UART_H */
