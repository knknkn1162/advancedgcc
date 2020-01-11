CC = gcc
CFLAGS += -DDEBUG -I./tools
LDFLAGS += -static -ffreestanding -nostartfiles
SUBDIR=tools

TOOLS_DIR = ./tools

.PHONY: all tools clean

all: tools program

# You can use unistd.h, system call wrapper
program: $(TOOLS_DIR)/mini-printf.o print.o check.o
	$(CC) $(LDFLAGS) -o $@ $^

tools:
	make -C tools

include ../general.mk
