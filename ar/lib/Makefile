CC = gcc
AR = ar
# r: insert new file(or replace) c: create s: create an archive index
ARFLAGS = rcs
TARGET=libsample.a

.PHONY: all

all: $(TARGET)

$(TARGET): math.o string.o
	$(AR) $(ARFLAGS) -o $@ $^

include ../../general.mk
