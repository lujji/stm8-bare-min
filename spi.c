#include "spi.h"
#include "stm8s.h"

void SPI_init() {
    PE_DDR = (1 << CS_PIN);
    PE_CR1 = (1 << CS_PIN);
    PE_CR2 = (1 << CS_PIN);
    //PE_ODR |= (1 << CS_PIN);

    SPI_CR2 = (1 << SPI_CR2_SSM) | (1 << SPI_CR2_SSI);
    SPI_CR1 = (1 << SPI_CR1_MSTR) | (1 << SPI_CR1_SPE) | (1 << SPI_CR1_BR1);
}

void SPI_write(uint8_t data) {
    while (!(SPI_SR & (1 << SPI_SR_TXE))) {
        /* Wait for transmission to complete */
    }
    SPI_DR = data;
}
