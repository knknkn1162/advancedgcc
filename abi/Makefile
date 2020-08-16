CC = gcc
LDFLAGS = -static

NOSTDLIB=0
OBJS = program.o add.o
TARGET = program
.PHONY: all run

all: program

program: $(OBJS)

include ../general.mk
run:
	-./program
