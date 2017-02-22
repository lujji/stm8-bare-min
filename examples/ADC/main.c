#include <stdint.h>
#include <stm8s.h>
#include <uart.h>
#include <stdio.h>
#include <delay.h>

uint16_t ADC_read() {
    uint8_t adcH, adcL;
    ADC_CR1 |= (1 << ADC_CR1_ADON);
    while(!(ADC_CSR & (1 << ADC_CSR_EOC)));
    adcL = ADC_DRL;
    adcH = ADC_DRH;
    ADC_CSR &= ~(1 << ADC_CSR_EOC); // clear EOC flag
    return (adcL | (adcH << 8));
}

void main() {
    uint16_t val;

    uart_init();

    /* configure ADC channel 4 (PD3)  */
    ADC_CSR |= (1 << 2);

    /* right-align data */
    ADC_CR2 |= (1 << ADC_CR2_ALIGN);

    /* wake ADC from power down */
    ADC_CR1 |= 1 << ADC_CR1_ADON;

    while (1) {
        val = ADC_read();
        printf("Channel4: %d\n", val);
        delay_ms(250);
    }
}
