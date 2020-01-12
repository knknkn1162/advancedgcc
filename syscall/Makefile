CC = gcc
LDFLAGS = -static

NOSTDLIB=0
OBJS = program.o
ifeq ($(NOSTDLIB), 0)
  LDFLAGS += -ffreestanding -nostartfiles
else
  CFLAGS += -DNOSTDLIB
  LDFLAGS += -nostdlib -fno-builtin
  OBJS += syscall.o
endif

.PHONY: all

all: program

program: $(OBJS)

include ../general.mk
