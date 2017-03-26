#include "eeprom.h"
#include "stm8s.h"

void eeprom_write(uint16_t addr, uint8_t *buf, int len) {
    /* unlock EEPROM */
    FLASH_DUKR = FLASH_DUKR_KEY1;
    FLASH_DUKR = FLASH_DUKR_KEY2;
    while (!(FLASH_IAPSR & (1 << FLASH_IAPSR_DUL)));

    /* write data */
    for (int i = 0; i < len; i++, addr++) {
        _MEM_(addr) = buf[i];
        /* not necessary on devices with no RWW support */
        // while (!(FLASH_IAPSR & (1 << FLASH_IAPSR_EOP)));
    }

    /* lock EEPROM */
    FLASH_IAPSR &= ~(1 << FLASH_IAPSR_DUL);
}

void eeprom_read(uint16_t addr, uint8_t *buf, int len) {
    while (len--)
        *(buf++) = _MEM_(addr++);
}
