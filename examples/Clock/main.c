#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stm8s.h>

int main() {
    /* Clock output on PE0 */
    PE_CR1 |= (1 << 0);
    CLK_CCOR |= (1 << CLK_CCOR_CCOEN) | (1 << 3);

    while (1) {

    }
}
