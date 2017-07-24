#include "ram.h"
#include <stm8s.h>

#pragma codeseg RAM0
void ram_blink(uint8_t count) {
    while (count--) {
        PD_ODR ^= (1 << 4);
        for (uint32_t i = 0; i < 0xFFF; i++)
            __asm__("nop");
    }
}
