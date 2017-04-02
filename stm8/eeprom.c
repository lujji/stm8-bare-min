#include "eeprom.h"

void eeprom_unlock() {
    FLASH_DUKR = FLASH_DUKR_KEY1;
    FLASH_DUKR = FLASH_DUKR_KEY2;
    while (!(FLASH_IAPSR & (1 << FLASH_IAPSR_DUL)));
}

void option_bytes_unlock() {
    FLASH_CR2 |= (1 << FLASH_CR2_OPT);
    FLASH_NCR2 &= ~(1 << FLASH_NCR2_NOPT);
}

void eeprom_lock() {
    FLASH_IAPSR &= ~(1 << FLASH_IAPSR_DUL);
}

void eeprom_wait_busy() {
    while (!(FLASH_IAPSR & (1 << FLASH_IAPSR_EOP)));
}
