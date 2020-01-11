CC = gcc
DEBUG = -DDEBUG
CFLAGS += $(DEBUG)

.PHONY: all

all: program

program: print.o main.o
	$(CC) $(LDFLAGS) -o $@ $^

include ../general.mk
