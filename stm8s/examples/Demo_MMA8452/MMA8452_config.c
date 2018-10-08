#include "MMA8452_config.h"
#include "MMA8452.h"
#include <stm8s.h>
#include <i2c.h>

void MMA8452_write_reg(uint8_t reg, uint8_t val) {
    i2c_start();
    i2c_write_addr((MMA8452_ADDR << 1) + I2C_WRITE);
    i2c_write(reg);
    i2c_write(val);
    i2c_stop();
}

uint8_t MMA8452_read_reg(uint8_t reg) {
    i2c_start();
    i2c_write_addr((MMA8452_ADDR << 1) + I2C_WRITE);
    i2c_write(reg);

    /* Generate repeated start and read one byte */
    i2c_start();
    i2c_write_addr((MMA8452_ADDR << 1) + I2C_READ);
    return i2c_read();
}

void MMA8452_read_regs(uint8_t *dest, uint8_t reg, uint8_t count) {
    i2c_start();
    i2c_write_addr((MMA8452_ADDR << 1) + I2C_WRITE);
    i2c_write(reg);

    /* Generate repeated start */
    i2c_start();
    i2c_write_addr((MMA8452_ADDR << 1) + I2C_READ);

    /* Read multiple registers */
    i2c_read_arr(dest, count);
}
