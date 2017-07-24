#ifndef UART_H
#define UART_H

#include <stdint.h>

#ifndef BAUDRATE
#define BAUDRATE 115200
#endif

#ifndef F_CPU
#warning "F_CPU not defined, using 2MHz by default"
#define F_CPU 2000000UL
#endif

/**
 * Initialize UART1.
 * Mode: 8-N-1, flow-control: none.
 *
 * PD5 -> TX
 * PD6 -> RX
 */
void uart_init();

void uart_write(uint8_t data);

uint8_t uart_read();

#endif /* UART_H */
