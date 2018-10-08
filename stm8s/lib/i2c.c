#include "i2c.h"
#include "stm8s.h"

void i2c_init() {
    I2C_FREQR = (1 << I2C_FREQR_FREQ1);
    I2C_CCRL = 0x0A; // 100kHz
    I2C_OARH = (1 << I2C_OARH_ADDMODE); // 7-bit addressing
    I2C_CR1 = (1 << I2C_CR1_PE);
}

void i2c_start() {
    I2C_CR2 |= (1 << I2C_CR2_START);
    while (!(I2C_SR1 & (1 << I2C_SR1_SB)));
}

void i2c_stop() {
    I2C_CR2 |= (1 << I2C_CR2_STOP);
    while (I2C_SR3 & (1 << I2C_SR3_MSL));
}

void i2c_write(uint8_t data) {
    I2C_DR = data;
    while (!(I2C_SR1 & (1 << I2C_SR1_TXE)));
}

void i2c_write_addr(uint8_t addr) {
    I2C_DR = addr;
    while (!(I2C_SR1 & (1 << I2C_SR1_ADDR)));
    (void) I2C_SR3; // check BUS_BUSY
    I2C_CR2 |= (1 << I2C_CR2_ACK);
}

uint8_t i2c_read() {
    I2C_CR2 &= ~(1 << I2C_CR2_ACK);
    i2c_stop();
    while (!(I2C_SR1 & (1 << I2C_SR1_RXNE)));
    return I2C_DR;
}

void i2c_read_arr(uint8_t *buf, int len) {
    while (len-- > 1) {
        I2C_CR2 |= (1 << I2C_CR2_ACK);
        while (!(I2C_SR1 & (1 << I2C_SR1_RXNE)));
        *(buf++) = I2C_DR;
    }
    *buf = i2c_read();
}
