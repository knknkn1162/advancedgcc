CC = gcc

.PHONY: all

all: program

program: main.o
	$(CC) $(LDFLAGS) -o $@ $^

include ../general.mk
