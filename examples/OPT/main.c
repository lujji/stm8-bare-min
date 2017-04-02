#include <stdio.h>
#include <string.h>
#include <stm8s.h>
#include <uart.h>
#include <eeprom.h>

int putchar(int c) {
    uart_write(c);
    return 0;
}

void opt_write() {
    /* new value for OPT5 (default is 0x00) */
    uint8_t opt5 = 0xb4;

    if (OPT5 != opt5) {
        /* unlock EEPROM and option bytes */
        eeprom_unlock();
        option_bytes_unlock();

        /* write option byte and it's complement */
        OPT5 = opt5;
        NOPT5 = ~opt5;

        /* wait until programming is finished and lock EEPROM */
        eeprom_wait_busy();
        eeprom_lock();
    }
}

void main() {
    uint8_t opt5 = OPT5;
    uart_init();
    printf("\n\nWriting option bytes..\n");
    opt_write();
    printf("OPT5 changed from %02x to %02x\n", opt5, OPT5);

    while (1) {

    }
}
