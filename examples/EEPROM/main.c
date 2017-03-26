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

int main() {
    const char data[] = "Test string";
    const int len = sizeof (data);

    uart_init();
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
