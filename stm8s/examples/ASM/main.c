#include <stdint.h>
#include <stdio.h>
#include <stm8s.h>
#include <uart.h>
#include <delay.h>

/**
 * Macros for fast IO control
 */
#define PIND4_SET()     __asm__("bset 0x500f, #4")
#define PIND4_RESET()   __asm__("bres 0x500f, #4")
#define PIND4_TOGGLE()  __asm__("bcpl 0x500f, #4")

/**
 * These symbols are declared in util.s
 */
extern uint8_t buf[16];
extern uint8_t increment_by_2(uint8_t x);
extern void fast_memcpy(uint8_t *dest, uint8_t *src, uint8_t len);

static uint8_t dest_buf[sizeof(buf)];

/**
 * Inline assembly example:
 * fill the array buf with a given value
 */
inline void buf_populate(uint8_t value, uint8_t len) {
    (void) value; // suppress compiler warning
    (void) len;
    __asm
    ; save registers
        push a
        pushw x
    ; x <- buf
        ldw x, #_buf
    loop0$:
    ; since we pushed 3 bytes on the stack the first
    ; function argument byte will be offset by 3 + 3 = 6 bytes,
    ; second - by 7 bytes, and so on.

    ; test if len == 0
        tnz (7, sp)
        jreq loop0_end$
    ; a <- value
        ld a, (6, sp)
    ; buf <- a
        ld (x), a
    ; x++
        incw x
    ; len--
        dec (7, sp)
        jra loop0$
    loop0_end$:
    ; restore registers
        popw x
        pop a
        ret
    __endasm;
}

/*
 * Redirect stdout to UART
 */
int putchar(int c) {
    uart_write(c);
    return 0;
}

void main() {
    uint8_t x = 0;
    uart_init();

    /* set PIND4 as output */
    PD_DDR = 1 << 4;
    PD_CR1 = 1 << 4;

    /* populate array and copy it's contents with assembly routines */
    buf_populate(42, sizeof(buf));
    fast_memcpy(dest_buf, buf, sizeof(dest_buf));

    /* print dest_buf */
    for (int i = 0; i < sizeof(dest_buf); i++)
        printf("%d, ", dest_buf[i]);

    while (1) {
        printf("\nx = %d", x);
        x = increment_by_2(x);
        PIND4_TOGGLE();
        delay_ms(500);
    }
}
