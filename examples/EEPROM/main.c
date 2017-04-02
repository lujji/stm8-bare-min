#include <stdio.h>
#include <string.h>
#include <stm8s.h>
#include <eeprom.h>
#include <uart.h>
#include <delay.h>

int putchar(int c) {
    uart_write(c);
    return 0;
}

inline void eeprom_read(uint16_t addr, uint8_t *buf, int len) {
    while (len--)
        *(buf++) = _MEM_(addr++);
}

void main() {
    const char data[] = "Test string";
    const int len = sizeof (data);
    uint16_t addr = EEPROM_START_ADDR;

    uart_init();
    printf("Writing EEPROM..\n");
    eeprom_unlock();
    for (int i = 0; i < len; i++, addr++) {
        _MEM_(addr) = data[i];
        /* not necessary on devices with no RWW support */
        // eeprom_wait_busy();
    }
    eeprom_lock();
    printf("Done!\n");

    while (1) {
        uint8_t buf[16];
        eeprom_read(EEPROM_START_ADDR, buf, len);
        printf("Reading EEPROM: %s\n", buf);
        delay_ms(250);
    }
}
