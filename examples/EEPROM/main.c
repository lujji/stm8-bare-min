#include <stdio.h>
#include <string.h>
#include <stm8s.h>
#include <flash.h>
#include <uart.h>
#include <delay.h>

int putchar(int c) {
    uart_write(c);
    return 0;
}

/**
 * Write data into EEPROM.
 *
 * @param addr start address
 * @param buf input buffer
 * @param len number of bytes to write
 */
void eeprom_write(uint16_t addr, uint8_t *buf, int len) {
    /* unlock EEPROM */
    FLASH_DUKR = FLASH_DUKR_KEY1;
    FLASH_DUKR = FLASH_DUKR_KEY2;

    if (FLASH_IAPSR & (1 << FLASH_IAPSR_DUL)) {
        /* EEPROM is unlocked, write data */
        for (int i = 0; i < len; i++, addr++)
            _MEM_(addr) = buf[i];
    }

    /* lock EEPROM */
    FLASH_IAPSR &= ~(1 << FLASH_IAPSR_DUL);
}

/**
 * Read data from EEPROM.
 *
 * @param addr start address
 * @param buf destination buffer
 * @param len number of bytes to read
 */
void eeprom_read(uint16_t addr, uint8_t *buf, int len) {
    while (len--)
        *(buf++) = _MEM_(addr++);
}

int main() {
    const char data[] = "Test string";
    const int len = sizeof (data);

    uart_init();
    delay_ms(250);

    printf("Writing EEPROM..\n");
    eeprom_write(EEPROM_START_ADDR, data, len);
    printf("Done!\n");

    while (1) {
        uint8_t buf[16];
        eeprom_read(EEPROM_START_ADDR, buf, len);
        printf("Reading EEPROM: %s\n", buf);
        delay_ms(250);
    }
}
