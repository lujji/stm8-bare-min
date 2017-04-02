#include <stdio.h>
#include <string.h>
#include <stm8s.h>
#include <uart.h>

/* Use last 64 bytes of flash for user data */
#define ID_ADDR                 (0x8000 + 0x1FC0)
#define USER_DATA_ADDR          (ID_ADDR + 1)

/* Tell compiler where the variables are located.
 * Defining variable as const will place it in the firmware binary */
__at(ID_ADDR) const uint8_t id = 42;
__at(USER_DATA_ADDR) uint8_t data[8];

int putchar(int c) {
    uart_write(c);
    return 0;
}

/**
 * Enable write access to flash memory
 */
static void flash_unlock() {
    FLASH_PUKR = FLASH_PUKR_KEY1;
    FLASH_PUKR = FLASH_PUKR_KEY2;
    while (!(FLASH_IAPSR & (1 << FLASH_IAPSR_PUL)));
}

/**
 * Disable write access to flash memory
 */
static inline void flash_lock() {
    FLASH_IAPSR &= ~(1 << FLASH_IAPSR_PUL);
}

/**
 * Wait for flash programming to finish
 * (note: not necessary on devices without RWW support)
 */
static inline void flash_busy_wait() {
    while (!(FLASH_IAPSR & (1 << FLASH_IAPSR_EOP)));
}

void main() {
    uart_init();
    printf("\nID = %d. Data[0] = %d\n", id, data[0]);

    flash_unlock();
    for (int i = 0; i < sizeof(data); i++) {
        /* same as _MEM_(USER_DATA_ADDR + i) += id + i */
        data[i] += id + i;
    }
    flash_lock();

    printf("Data[0] = %d\n", data[0]);

    while (1) {

    }
}
