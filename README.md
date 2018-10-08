# stm8-bare-min

Tiny peripheral library for STM8. This library was developed as a supplement to a series of [blog posts](https://lujji.github.io/blog/bare-metal-programming-stm8/) while I was experimenting with STM8 microcontrollers. Tested with SDCC compiler only.

## Code Structure
* `stm8l` and `stm8s` contain libraries and examples for corresponding microcontroller families
* `lib` contains `stm8s.h` or `stm8l.h` header with register definitions and very basic peripheral drivers
* `examples` contains directories with example code

## Building
Dependencies:
 1. [sdcc](https://sourceforge.net/projects/sdcc/)
 2. [stm8flash](https://github.com/vdudouyt/stm8flash)

Building and flashing example project:

```
cd ./stm8s/examples/<example>
make flash
```
Uncomment `--peep-file $(LIBDIR)/util/extra.def` option in the Makefile to enable additional optimizer rules.

## Bugs
Due to SDCC [Bug #2673](https://sourceforge.net/p/sdcc/bugs/2673/) it is recommended to compile with `--nolospre` flag.
