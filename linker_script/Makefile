CC = x86_64-linux-gnu-gcc
CFLAGS += -DDEBUG -I./tools
LDFLAGS += -static -ffreestanding -nostartfiles

.PHONY: all clean

all: program

# You can use unistd.h, system call wrapper
program: main.o
	$(CC) \
	$(LDFLAGS) \
	-o $@ \
	-T app.lds \
	$^

include ../general.mk

