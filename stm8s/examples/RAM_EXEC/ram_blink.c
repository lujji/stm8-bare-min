#include "ram.h"
#include <stm8s.h>

#pragma codeseg RAM0
void ram_blink(uint8_t count) {
    while (count--) {
        LED_ODR ^= (1 << LED_PIN);
        for (uint32_t i = 0; i < 0xFFFF; i++)
            nop();
    }
}
