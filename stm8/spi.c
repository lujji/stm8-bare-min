#include "spi.h"
#include "stm8s.h"

void SPI_init() {
    SPI_CR1 = (1 << SPI_CR1_MSTR) | (1 << SPI_CR1_SPE) | (1 << SPI_CR1_BR1);
    SPI_CR2 = (1 << SPI_CR2_SSM) | (1 << SPI_CR2_SSI) | (1 << SPI_CR2_BDM) | (1 << SPI_CR2_BDOE);
}

uint8_t SPI_read() {
    SPI_write(0xFF);
    while (!(SPI_SR & (1 << SPI_SR_RXNE)));
    return SPI_DR;
}

void SPI_write(uint8_t data) {
    SPI_DR = data;
    while (!(SPI_SR & (1 << SPI_SR_TXE)));
}
