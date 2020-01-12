CC = x86_64-linux-gnu-gcc
LDFLAGS += -static -ffreestanding -nostartfiles -L app.lds

.PHONY: all clean

all: program

# You can use unistd.h, system call wrapper
## if you specify entrypoint, append `-e _main`
program: startup.o program.o
	$(CC) \
	$(LDFLAGS) \
	-o $@ \
	$^

include ../general.mk
