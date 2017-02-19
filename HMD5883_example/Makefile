export PATH := $(PATH):$(HOME)/local/sdcc/bin

MCU  = stm8s003f3
ARCH = stm8

F_CPU    = 2000000
TARGET   = main.ihx

SRCS     = $(wildcard *.c ../stm8/*.c)
OBJS     = $(SRCS:.c=.rel)

CC       = sdcc
LD       = sdld
CFLAGS   = -m$(ARCH) -p$(MCU) --std-sdcc11 -DF_CPU=$(F_CPU)UL
CFLAGS  += --stack-auto --noinduction --use-non-free -I. -I../stm8
LDFLAGS  = -m$(ARCH) -l$(ARCH) --out-fmt-ihx

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

%.rel: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

flash: $(TARGET)
	stm8flash -c stlinkv2 -p $(MCU) -w $(TARGET)

clean:
	rm -f *.map *.asm *.rel *.ihx *.o *.sym *.lk *.lst *.rst *.cdb

.PHONY: clean all program