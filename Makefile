PROGRAM_DIRS = compile_switch freestanding_print
.PHONY: all clean run $(PROGRAM_DIRS)

all: clean $(PROGRAM_DIRS)

compile_switch:
	make -C compile_switch
freestanding_print:
	make -C freestanding_print

run: all
	make run -C compile_switch
	make run -C freestanding_print

clean:
	$(RM) *.o *.a
	make clean -C compile_switch
	make clean -C freestanding_print
