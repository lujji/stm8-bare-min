#ifndef FLASH_H
#define FLASH_H

#include <stdint.h>

/* Access memory by address */
#define _MEM_(mem_addr)        (*(volatile uint8_t *)(mem_addr))

/* EEPROM */
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

#endif /* FLASH_H */
