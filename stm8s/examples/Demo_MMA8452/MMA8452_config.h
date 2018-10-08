/*
 * Platform-dependent functions
 */
#ifndef MMA8452_CONFIG_H
#define MMA8452_CONFIG_H

#include <stdint.h>

/**
 * Write a single register.
 *
 * @param reg register address
 * @param val value to write
 */
void MMA8452_write_reg(uint8_t reg, uint8_t val);

/**
 * Sequentially read multiple registers.
 *
 * @param dest register address
 * @param reg start register address
 * @param count registers count
 */
void MMA8452_read_regs(uint8_t *dest, uint8_t reg, uint8_t count);

/**
 * Read a single register.
 *
 * @param reg register address
 */
uint8_t MMA8452_read_reg(uint8_t reg);

#endif /* MMA8452_CONFIG_H */
