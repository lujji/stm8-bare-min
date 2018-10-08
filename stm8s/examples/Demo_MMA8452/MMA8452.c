#include "MMA8452_config.h"
#include "MMA8452.h"

void MMA8452_init() {
    /* High-pass filter enabled, full-scale range = 8g */
    MMA8452_write_reg(MMA8452_XYZ_DATA_CFG, (1 << 4) | (1 << 1));

    /* Filter cutoff freq = 2 Hz */
    MMA8452_write_reg(MMA8452_HP_FILTER_CUTOFF, (1 << 1) | (1 << 0));

    /* Active mode */
    MMA8452_write_reg(MMA8452_CTRL_REG1, (1 << 2) | (1 << 0));
}

uint8_t MMA8452_readID() {
    return MMA8452_read_reg(MMA8452_WHO_AM_I);
}

void MMA8452_readXYZ(int16_t *x, int16_t *y, int16_t *z) {
    uint8_t buf[6];
    MMA8452_read_regs(buf, MMA8452_OUT_X_MSB, 6);
    *x = ~((buf[0] << 8) | buf[1]);
    *y = ~((buf[2] << 8) | buf[3]);
    *z = ~((buf[4] << 8) | buf[5]);
}
