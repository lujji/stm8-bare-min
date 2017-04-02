#include <stm8s.h>

/* Clock output selection CCOSEL[3:0] */
#define F_CPU_CCO 0b0100
#define F_LSI_CCO 0b0001
#define F_HSI_CCO 0b1011
#define F_HSE_CCO 0b0010

void main() {
    /* Enable HSE crystal oscillator */
    CLK_ECKR |= (1 << CLK_ECKR_HSEEN);
    while (!(CLK_ECKR & (1 << CLK_ECKR_HSERDY)));

    /* Switch master clock to HSE */
    CLK_SWR = 0xB4;
    while (!(CLK_SWCR & (1 << CLK_SWCR_SWIF)));
    CLK_SWCR |= (1 << CLK_SWCR_SWEN);

    /* Clock output on PC4 */
    PC_DDR |= (1 << 4);
    PC_CR1 |= (1 << 4);
    PC_CR2 |= (1 << 4);
    CLK_CCOR |= (1 << CLK_CCOR_CCOEN) | (F_CPU_CCO << 1);

    while (1) {
        // do nothing
    }
}
