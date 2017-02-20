#ifndef SPI_H
#define SPI_H

#include <stdint.h>

/*
 * SPI pinout:
 * SCK  -> PC5
 * MOSI -> PC6
 * MISO -> PC7
 * CS   -> user defined
 */
void SPI_init();

void SPI_write(uint8_t data);

uint8_t SPI_read();

#endif /* SPI_H */

