#include <stdint.h>
#include <stm8s.h>
#include <delay.h>

#define LED_PIN     4

void main() {
    PD_DDR |= (1 << LED_PIN);
    PD_CR1 |= (1 << LED_PIN);

    while (1) {
        PD_ODR ^= (1 << LED_PIN);
        delay_ms(250);
    }
}
