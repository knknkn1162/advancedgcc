CC = gcc
DEBUG = -DCONDITION=1
CFLAGS += $(DEBUG)

.PHONY: all

all: program

program: print.o main.o
	$(CC) $(LDFLAGS) -o $@ $^

include ../general.mk
