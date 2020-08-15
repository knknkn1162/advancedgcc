TARGET = test.o
.PHONY: all clean
CC = gcc

.PHONY: all

all: program

.ONESHELL:
test.o:
	cat <<EOF | gcc -xc -c -o $@ -
	int foo(void) { return 100; }
	EOF

program: program.o test.o

include ../general.mk
