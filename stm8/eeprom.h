#ifndef EEPROM_H
#define EEPROM_H

#include <stdint.h>

#define EEPROM_START_ADDR       0x4000
#define EEPROM_END_ADDR         0x407F

/**
 * Write data into EEPROM.
 *
 * @param addr start address
 * @param buf input buffer
 * @param len number of bytes to write
 */
void eeprom_write(uint16_t addr, uint8_t *buf, int len);

/**
 * Read data from EEPROM.
 *
 * @param addr start address
 * @param buf destination buffer
 * @param len number of bytes to read
 */
void eeprom_read(uint16_t addr, uint8_t *buf, int len);

#endif /* EEPROM_H */
