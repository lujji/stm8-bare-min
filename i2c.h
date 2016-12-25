#ifndef I2C_H
#define I2C_H

#include <stdint.h>

#define I2C_READ            0x01
#define I2C_WRITE           0x00

void i2c_init();
void i2c_start();
void i2c_stop();
void i2c_write(uint8_t data);
void i2c_write_addr(uint8_t addr);
void i2c_read_arr(uint8_t *buf, int len);
uint8_t i2c_read(uint8_t ack);

#endif /* I2C_H */

