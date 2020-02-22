TOOLPREFIX=x86_64-linux-gnu-
CC = $(TOOLPREFIX)gcc
LD = $(TOOLPREFIX)ld
OBJCOPY = $(TOOLPREFIX)objcopy

PAYLOAD_SRC = sample.c
PAYLOAD_BIN = $(patsubst %.c,%, $(PAYLOAD_SRC))
PAYLOAD_OBJ = $(patsubst %.c,%.o, $(PAYLOAD_SRC))
PAYLOAD = $(PAYLOAD_BIN)_payload
OBJS= payload.o

CLEAN_FILES = $(PAYLOAD) $(PAYLOAD_BIN)

CFLAGS += -DPAYLOAD=\"$(PAYLOAD)\"
ASFLAGS += $(CFLAGS)


.PHONY: all clean

all: program

program: $(OBJS)

payload.o: $(PAYLOAD)

$(PAYLOAD_BIN): $(PAYLOAD_OBJ)
	$(CC) \
	-static \
	-T sample.lds \
	-nostartfiles \
	-o $@ \
	$^

$(PAYLOAD): $(PAYLOAD_BIN)
	$(OBJCOPY) -O binary $^ $@

include ../general.mk
