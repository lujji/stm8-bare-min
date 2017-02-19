#include <stdint.h>
#include "stm8s.h"
#include "delay.h"

#define LED_PIN     3

void timer_isr (void) __interrupt (TIM4_ISR) {
    PD_ODR ^= (1 << LED_PIN);
    TIM4_SR &= ~(1 << TIM4_SR_UIF);
}

int main() {
    enable_interrupts();

    /* Set PD3 as output */
    PD_DDR |= (1 << LED_PIN);
    PD_CR1 |= (1 << LED_PIN);

    /* Prescaler = 128 */

    TIM4_ARR = 159;
    TIM4_PSCR = 0b00000111;
    TIM4_IER |= (1 << TIM4_IER_UIE); // Enable Update Interrupt
    TIM4_CR1 |= (1 << TIM4_CR1_CEN); // Enable TIM4


    while (1) {
        //delay_ms(2);
    }
}
