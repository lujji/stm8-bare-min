#ifndef SPI_H
#define SPI_H

#include <stdint.h>

#define CS_PIN 5

/*
 * SPI pinout:
 * SCK  -> PC5
 * MOSI -> PC6
 * MISO -> PC7
 * CS   -> PE5
 */
void SPI_init();

void SPI_write(uint8_t data);

#endif /* SPI_H */

