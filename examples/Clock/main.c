#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stm8s.h>

int main() {
    /* Enable HSE crystal oscillator */
    CLK_ECKR |= (1 << CLK_ECKR_HSEEN);
    while (!(CLK_ECKR & (1 << CLK_ECKR_HSERDY)));

    /* Switch master clock to HSE */
    CLK_SWR = 0xB4;
    while (!(CLK_SWCR & (1 << CLK_SWCR_SWIF)));
    CLK_SWCR |= (1 << CLK_SWCR_SWEN);

    /* Clock output on PC4 */
    PC_CR1 |= (1 << 4);
    CLK_CCOR |= (1 << CLK_CCOR_CCOEN) | (1 << 3);

    while (1) {
        // do nothing
    }
}
