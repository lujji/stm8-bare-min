#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stm8s.h>
#include <delay.h>
#include <uart.h>
#include <i2c.h>

#define HMC5883_ADDR        (0x1E << 1)
#define HMC5883_CR_A        0x00
#define HMC5883_CR_B        0x01
#define HMC5883_MODE        0x02
#define HMC5883_DATA_OUT    0x03
#define HMC5883_ID_REG_A    0x0A

int putchar(int c) {
    uart_write(c);
    return 0;
}

void hmc5883_get_id(uint8_t *id) {
    i2c_start();
    i2c_write_addr(HMC5883_ADDR + I2C_WRITE);
    i2c_write(HMC5883_ID_REG_A);
    i2c_stop();

    i2c_start();
    i2c_write_addr(HMC5883_ADDR + I2C_READ);
    i2c_read_arr(id, 3);
}

void measure() {
    int16_t x, y, z;
    uint8_t buf[6];

    /* Set gain */
    i2c_start();
    i2c_write_addr(HMC5883_ADDR + I2C_WRITE);
    i2c_write(HMC5883_CR_B);
    i2c_write(0xe0);
    i2c_stop();

    /* Set cont. measurement mode */
    i2c_start();
    i2c_write_addr(HMC5883_ADDR + I2C_WRITE);
    i2c_write(HMC5883_MODE);
    i2c_write(0x00);
    i2c_stop();

    delay_ms(6);

    /* Start reading at DATA_OUT */
    i2c_start();
    i2c_write_addr(HMC5883_ADDR + I2C_WRITE);
    i2c_write(HMC5883_DATA_OUT);
    i2c_stop();

    /* Read axes */
    i2c_start();
    i2c_write_addr(HMC5883_ADDR + I2C_READ);
    i2c_read_arr(buf, 6);

    x = (buf[0] << 8) | buf[1];
    y = (buf[2] << 8) | buf[3];
    z = (buf[4] << 8) | buf[5];

    printf("x: %d y: %d z: %d\n", x, y, z);
}

void main() {
    uint8_t id[3];
    uart_init();
    i2c_init();
    hmc5883_get_id(id);
    printf("Device ID: %c%c%c\n", id[0], id[1], id[2]);

    while (1) {
        measure();
        delay_ms(250);
    }
}
