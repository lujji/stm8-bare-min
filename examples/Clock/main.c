#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stm8s.h"

/**
 * Clock output on PE0
 */
void ckout() {
    PE_CR1 |= (1 << 0);
    CLK_CCOR |= (1 << CLK_CCOR_CCOEN) | (1 << 3);
}

int main() {
    ckout();

    while (1) {

    }
}
