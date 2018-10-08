#include <stdint.h>
#include <stm8s.h>
#include <delay.h>

#define OUTPUT_PIN      3

void timer_isr() __interrupt(TIM4_ISR) {
    PD_ODR ^= (1 << OUTPUT_PIN);
    TIM4_SR &= ~(1 << TIM4_SR_UIF);
}

void main() {
    enable_interrupts();

    /* Set PD3 as output */
    PD_DDR |= (1 << OUTPUT_PIN);
    PD_CR1 |= (1 << OUTPUT_PIN);

    /* Prescaler = 128 */
    TIM4_PSCR = 0b00000111;

    /* Frequency = F_CLK / (2 * prescaler * (1 + ARR))
     *           = 2 MHz / (2 * 128 * (1 + 77)) = 100 Hz */
    TIM4_ARR = 77;

    TIM4_IER |= (1 << TIM4_IER_UIE); // Enable Update Interrupt
    TIM4_CR1 |= (1 << TIM4_CR1_CEN); // Enable TIM4

    while (1) {
        // do nothing
    }
}
