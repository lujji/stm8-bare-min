#include <stdint.h>
#include <stm8s.h>
#include <delay.h>
#include <uart.h>
#include "ram.h"

static volatile uint8_t RAM0_len, RAM1_len;
static uint8_t f_ram[128];

static void (*blink)(uint8_t count);
static void (*uart_puts)(uint8_t *str);

/**
 * Get RAM0 and RAM1 section length and store them in
 * RAM0_len and RAM1_len respectively
 */
inline void get_ram_sections_length() {
    __asm__("mov _RAM0_len, #l_RAM0");
    __asm__("mov _RAM1_len, #l_RAM1");
}

/**
 * Copy routines from flash into RAM
 */
static void ram_cpy() {
    get_ram_sections_length();
    for (uint8_t i = 0; i < RAM0_len; i++)
        f_ram[i] = ((uint8_t *) ram_blink)[i];
    for (uint8_t i = 0; i < RAM1_len; i++)
        f_ram[RAM0_len + i] = ((uint8_t *) ram_uart_puts)[i];

    blink = (void (*)(uint8_t)) f_ram;
    uart_puts = (void (*)(uint8_t *)) &f_ram[RAM0_len];
}

void main() {
    PD_DDR |= (1 << 4);
    PD_CR1 |= (1 << 4);
    uart_init();
    ram_cpy();

    while (1) {
        uart_puts("Executing from RAM\n");
        blink(10);
        delay_ms(500);
    }
}
