.module UTIL

.globl _buf
.globl _increment_by_2
.globl _fast_memcpy

.area DATA
_buf:
    .ds 16

.area CODE
_increment_by_2:
    ; (0x03, sp) -> first argument byte
    ld a, (0x03, sp)
    add	a, #2
    ret

_fast_memcpy:
    dest = 0x03
    src  = 0x05
    len  = 0x07
    ldw x, (dest, sp)
    ldw y, (src, sp)
loop0$:
    tnz (len, sp)
    jreq loop0_end$

; loop body
    ld a, (y)
    ld (x), a
    incw x
    incw y

    dec (len, sp)
    jra loop0$
loop0_end$:
    ret
