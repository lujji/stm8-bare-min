#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stm8s.h"
#include "delay.h"
#include "uart.h"
#include "i2c.h"

#define LED_PIN             0

#define HMC5883_ADDR        (0x1E << 1)
#define HMC5883_CR_A        0x00
#define HMC5883_CR_B        0x01
#define HMC5883_MODE        0x02
#define HMC5883_DATA_OUT    0x03
#define HMC5883_ID_REG_A    0x0A


uint8_t id[3];

void hmc5883_get_id(uint8_t *id) {
    i2c_start();
    i2c_write_addr(HMC5883_ADDR + I2C_WRITE);
    i2c_write(HMC5883_ID_REG_A);
    i2c_stop();

    i2c_start();
    i2c_write_addr(HMC5883_ADDR + I2C_READ);
    i2c_read_arr(id, 3);
}

int x, y, z;

void measure() {
    /* Gain */
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

    /* Start reading @ DATA_OUT */
    i2c_start();
    i2c_write_addr(HMC5883_ADDR + I2C_WRITE);
    i2c_write(HMC5883_DATA_OUT);
    i2c_stop();

    /* Read axis */
    i2c_start();
    i2c_write_addr(HMC5883_ADDR + I2C_READ);
    x = i2c_read(1) << 8;
    x |= i2c_read(1);
    z = i2c_read(1) << 8;
    z |= i2c_read(1);
    y = i2c_read(1) << 8;
    y |= i2c_read(0);
    i2c_stop();

    printf("x: %d y: %d z: %d\n", x, y, z);
}

void show_id() {
    hmc5883_get_id(id);
    uart_write('I');
    uart_write('d');
    uart_write(':');
    uart_write(id[0]);
    uart_write(id[1]);
    uart_write(id[2]);
    uart_write('\n');
}

int main() {
    uint8_t id[3];
    uart_init();
    i2c_init();
    PD_DDR |= (1 << LED_PIN);
    while (1) {
        PD_ODR ^= (1 << LED_PIN);
        hmc5883_get_id(id);
        printf("Device ID: %c%c%c\n", id[0], id[1], id[2]);
        delay_ms(250);
    }
}
