# stm8-bare-min

Tiny peripheral library for STM8. This library was developed as a supplement to [this blog post](https://lujji.github.io/blog/bare-metal-programming-stm8/) while I was experimenting with STM8. Tested with SDCC compiler only.

## Code Structure
* `stm8` contains `stm8s.h` header with register definitions and very basic drivers for some peripherals
* `examples` contains directories with example code

## Building
Dependencies:
    1. [sdcc](https://sourceforge.net/projects/sdcc/)
    2. [stm8flash](https://github.com/vdudouyt/stm8flash)

Building example project:

```
cd ./examples/<example>
make && make flash
```
