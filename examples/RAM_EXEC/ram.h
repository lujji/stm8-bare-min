#ifndef RAM_H
#define RAM_H

#include <stdint.h>

void ram_blink(uint8_t count);
void ram_uart_puts(uint8_t *str);

#endif /* RAM_H */
