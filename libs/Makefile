CC = gcc
SUBDIR = lib
CFLAGS=-I$(SUBDIR)
LDFLAGS = -L$(SUBDIR) -static
LDLIBS = -lsample
SAMPLE_LIB = $(SUBDIR)/libsample.a

.PHONY: all $(SUBDIR) program2

all: $(SUBDIR) program

# The order of `-L` and `-l` option is important
# implicit rules: `$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@` see the topmost README.md
program: program.o empty.o

# or you can directly add archive to object list
program2: program.o $(SAMPLE_LIB)
	$(CC) $(LDFLAGS) -o program $^

$(SUBDIR):
	make -C $(SUBDIR)

include ../general.mk
