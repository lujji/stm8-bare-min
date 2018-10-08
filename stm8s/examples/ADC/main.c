#include <stdint.h>
#include <stdio.h>
#include <stm8s.h>
#include <uart.h>
#include <delay.h>

#define V_REF 3.3

/*
 * Redirect stdout to UART
 */
int putchar(int c) {
    uart_write(c);
    return 0;
}

uint16_t ADC_read() {
    uint8_t adcH, adcL;
    ADC1_CR1 |= (1 << ADC1_CR1_ADON);
    while (!(ADC1_CSR & (1 << ADC1_CSR_EOC)));
    adcL = ADC1_DRL;
    adcH = ADC1_DRH;
    ADC1_CSR &= ~(1 << ADC1_CSR_EOC); // clear EOC flag
    return (adcL | (adcH << 8));
}

void main() {
    uart_init();

    /* configure ADC channel 4 (PD3)  */
    ADC1_CSR |= (1 << 2);

    /* right-align data */
    ADC1_CR2 |= (1 << ADC1_CR2_ALIGN);

    /* wake ADC from power down */
    ADC1_CR1 |= (1 << ADC1_CR1_ADON);

    while (1) {
        uint16_t val = ADC_read();
        float voltage = (V_REF / 1024.0) * val * 1000;
        printf("Channel4: %d mV\n", (uint16_t) voltage);
        delay_ms(250);
    }
}
