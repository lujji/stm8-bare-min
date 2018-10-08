#ifndef DELAY_H
#define DELAY_H

#ifndef F_CPU
#warning "F_CPU not defined, using 2MHz by default"
#define F_CPU 2000000UL
#endif

#include <stdint.h>

inline void delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ((F_CPU / 18 / 1000UL) * ms); i++) {
        __asm__("nop");
    }
}

#endif /* DELAY_H */
