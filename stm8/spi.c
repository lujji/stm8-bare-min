#include "spi.h"
#include "stm8s.h"

void SPI_init() {
//     PE_DDR = (1 << CS_PIN);
//     PE_CR1 = (1 << CS_PIN);
//     PE_CR2 = (1 << CS_PIN);
    //PE_ODR |= (1 << CS_PIN);


    SPI_CR1 = (1 << SPI_CR1_MSTR) | (1 << SPI_CR1_SPE) | (1 << SPI_CR1_BR1);
    SPI_CR2 = (1 << SPI_CR2_SSM) | (1 << SPI_CR2_SSI) | (1 << SPI_CR2_BDM) | (1 << SPI_CR2_BDOE);
    //| (1 << SPI_CR1_CPOL) | (1 << SPI_CR1_CPHA);
}

void SPI_write(uint8_t data) {
    SPI_DR = data;
    while (!(SPI_SR & (1 << SPI_SR_TXE))) {
        /* Wait for transmission to complete */
    }
}
