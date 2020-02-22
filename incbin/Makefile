TOOLPREFIX=x86_64-linux-gnu-
CC = $(TOOLPREFIX)gcc
AR = $(TOOLPREFIX)ar
LD = $(TOOLPREFIX)ld
OBJCOPY = $(TOOLPREFIX)objcopy

ARFLAGS = rcv

PAYLOAD_SRC = sample.c
PAYLOAD_BIN = $(patsubst %.c,%, $(PAYLOAD_SRC))
PAYLOAD_OBJ = $(patsubst %.c,%.o, $(PAYLOAD_SRC))
PAYLOAD = $(PAYLOAD_BIN)_payload
OBJ= payload.o

CLEAN_FILES = $(PAYLOAD) $(PAYLOAD_BIN)

CFLAGS += -DPAYLOAD=\"$(PAYLOAD)\"
ASFLAGS += $(CFLAGS)


.PHONY: all clean

all: program

program: $(OBJ)

$(OBJ): $(PAYLOAD)

$(PAYLOAD_BIN): $(PAYLOAD_OBJ)
	$(CC) \
	-static \
	-nostartfiles \
	-o $@ \
	$^ \
	-Wl,-T sample.lds


$(PAYLOAD): $(PAYLOAD_BIN)
	$(OBJCOPY) -O binary $^ $@

include ../general.mk
