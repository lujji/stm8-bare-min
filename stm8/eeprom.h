#ifndef EEPROM_H
#define EEPROM_H

#include "stm8s.h"

#define EEPROM_START_ADDR      0x4000
#define EEPROM_END_ADDR        0x407F

/* Option bytes */
#define OPT0                   _MEM_(0x4800)
#define OPT1                   _MEM_(0x4801)
#define NOPT1                  _MEM_(0x4802)
#define OPT2                   _MEM_(0x4803)
#define NOPT2                  _MEM_(0x4804)
#define OPT3                   _MEM_(0x4805)
#define NOPT3                  _MEM_(0x4806)
#define OPT4                   _MEM_(0x4807)
#define NOPT4                  _MEM_(0x4808)
#define OPT5                   _MEM_(0x4809)
#define NOPT5                  _MEM_(0x480A)

/**
 * Enable write access to EEPROM.
 */
void eeprom_unlock();


/**
 * Enable write access to option bytes.
 * EEPROM must be unlocked first.
 */
void option_bytes_unlock();


/**
 * Disable write access to EEPROM.
 */
void eeprom_lock();

/**
 * Wait until programming is finished.
 * Not necessary on devices with no RWW support.
 */
void eeprom_wait_busy();

#endif /* EEPROM_H */
