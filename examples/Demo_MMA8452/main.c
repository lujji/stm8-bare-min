#include <stdio.h>
#include <string.h>
#include <stm8s.h>
#include <i2c.h>
#include <delay.h>
#include "HD44780.h"

/* Device address: 0x1C/0x1D for SA0 LOW/HIGH */
#define MMA8452_ADDR        (0x1D << 1)
#define MMA8452_DEVICE_ID   0x2A

#define MMA8452_STATUS      0x00
#define MMA8452_WHO_AM_I    0x0D
#define MMA8452_OUT_X_MSB   0x01
#define MMA8452_OUT_X_LSB   0x02
#define MMA8452_OUT_Y_MSB   0x03
#define MMA8452_OUT_Y_LSB   0x04
#define MMA8452_OUT_Z_MSB   0x05
#define MMA8452_OUT_Z_LSB   0x06
#define MMA8452_CTRL_REG1   0x2A
#define MMA8452_CTRL_REG2   0x2B
#define MMA8452_CTRL_REG3   0x2C
#define MMA8452_CTRL_REG4   0x2D
#define MMA8452_CTRL_REG5   0x2E

/*
    0b00011100 <- ADDR
    0b00111000 <- I2C_ADDR
    0b00111001 <- READ
    0b00111011 <- WRITE

    (ADDR + 1) << 1 = WRITE
    (ADDR + 1)
*/

/*
 * Redirect stdout to LCD
 */
// int putchar(int c) {
//     LCD_putc(c);
//     return 0;
// }

void read_id() {
    uint8_t id;
    i2c_start();
    i2c_write_addr(MMA8452_ADDR + I2C_WRITE);
    i2c_write(MMA8452_WHO_AM_I);
    i2c_stop();

    //printf("stage2");
    i2c_start();
    i2c_write_addr(MMA8452_ADDR + I2C_READ);
    id = i2c_read(0);
    i2c_stop();
    //printf("ID: 0x%02X", id);
}

#define HMC5883_ADDR        (0x1E << 1)
#define HMC5883_CR_A        0x00
#define HMC5883_CR_B        0x01
#define HMC5883_MODE        0x02
#define HMC5883_DATA_OUT    0x03
#define HMC5883_ID_REG_A    0x0A

void hmc5883_get_id(uint8_t *id) {
    i2c_start();
    i2c_write_addr(HMC5883_ADDR + I2C_WRITE);
    i2c_write(HMC5883_ID_REG_A);
    i2c_stop();

    i2c_start();
    i2c_write_addr(HMC5883_ADDR + I2C_READ);
    i2c_read_arr(id, 3);
    //i2c_stop();
}

int main() {
    uint8_t counter = 0;
    uint8_t id[4];


    //LCD_init();
    //LCD_goto(1, 0);
    //printf("init..");
    //delay_ms(250);
    //i2c_init();
    PB_DDR |= ((1 << 4) | (1 << 5));
    PB_CR1 |= ((1 << 4) | (1 << 5));
    PB_CR2 |= ((1 << 4) | (1 << 5));

    while (1) {
        //hmc5883_get_id(id);
        PB_ODR ^= (1 << 4);
        PB_ODR ^= (1 << 5);
        delay_ms(10);
    }
}
