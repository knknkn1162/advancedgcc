CC = gcc
LD = gcc
CFLAGS += -DDEBUG -I./tools
LDFLAGS += -static -ffreestanding -nostartfiles
SUBDIR=tools

TOOLS_DIR = ./tools

.PHONY: all tools clean

all: tools program

program: $(TOOLS_DIR)/mini-printf.o print.o check.o
	$(LD) $(LDFLAGS) -o $@ $^

tools:
	make -C tools

include ../general.mk
