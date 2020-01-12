CC = x86_64-linux-gnu-gcc
LD = x86_64-linux-gnu-gcc
LDFLAGS += -static -ffreestanding -nostartfiles
LDFLAGS += -ffreestanding -nostartfiles
LDFLAGS += -T app.lds


.PHONY: all clean

all: program

# You can use unistd.h, system call wrapper
## if you specify entrypoint, append `-e _main`
program: startup.o initfini.o program.o

include ../general.mk
