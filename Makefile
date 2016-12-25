export PATH := $(PATH):$(HOME)/local/sdcc/bin

MCU  = stm8s003f3
ARCH = stm8

TARGET   = main.ihx

CC       = sdcc
LD       = sdld
CFLAGS   = -m$(ARCH) -p$(MCU) --std-sdcc11
CFLAGS  += --stack-auto --noinduction --use-non-free -I.
LFLAGS   = -m$(ARCH) -l$(ARCH) --out-fmt-ihx

SRCS  = $(wildcard *.c)
OBJS  = $(SRCS:.c=.rel)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

%.rel: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

flash: $(TARGET)
	stm8flash -c stlinkv2 -p $(MCU) -w $(TARGET)

clean:
	rm -f *.map *.asm *.rel *.ihx *.o *.sym *.lk *.lst *.rst *.cdb

.PHONY: clean all program