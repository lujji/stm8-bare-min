#include <stdio.h>
#include <string.h>
#include <stm8s.h>
#include <uart.h>
#include <opt.h>

int putchar(int c) {
    uart_write(c);
    return 0;
}

void opt_write() {
    /* new value for OPT5 (default is 0x00) */
    uint8_t opt5 = 0xb4;

    if (OPT5 != opt5) {
        /* unlock EEPROM */
        FLASH_DUKR = FLASH_DUKR_KEY1;
        FLASH_DUKR = FLASH_DUKR_KEY2;
        while (!(FLASH_IAPSR & (1 << FLASH_IAPSR_DUL)));

        /* unlock option bytes */
        FLASH_CR2 |= (1 << FLASH_CR2_OPT);
        FLASH_NCR2 &= ~(1 << FLASH_NCR2_NOPT);

        /* write option byte and it's complement */
        OPT5 = opt5;
        NOPT5 = ~opt5;

        /* wait until programming is finished */
        while (!(FLASH_IAPSR & (1 << FLASH_IAPSR_EOP)));

        /* lock EEPROM */
        FLASH_IAPSR &= ~(1 << FLASH_IAPSR_DUL);
    }
}

int main() {
    uint8_t opt5 = OPT5;
    uart_init();
    printf("\n\nWriting option bytes..\n");
    opt_write();
    printf("OPT5 changed from %02x to %02x\n", opt5, OPT5);

    while (1) {

    }
}
