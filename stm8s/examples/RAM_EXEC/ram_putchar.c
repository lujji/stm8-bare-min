#include "ram.h"
#include <stm8s.h>

#pragma codeseg RAM1
void ram_uart_puts(uint8_t *str) {
    while (*str) {
        UART1_DR = *str++;
        while (!(UART1_SR & (1 << UART1_SR_TC)));
    }
}
