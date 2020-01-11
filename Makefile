PROGRAM_DIRS = compile_switch freestanding_print

.PHONY: all clean run $(PROGRAM_DIRS)

build: clean $(PROGRAM_DIRS)

compile_switch:
	make -C compile_switch
freestanding_print:
	make -C freestanding_print

run: build
	echo "+ run all programs:"
	echo "+ compile_switch, error_directive"
	make run -C compile_switch
	make run -C error_directive
	echo "+ # macro"
	make run -C stringizing_operator
	echo "+ using archive library"
	make run -C ar
	echo "+ freestanding_print:"
	make run -C freestanding_print

clean:
	$(RM) *.o *.a
	make clean -C compile_switch
	make clean -C freestanding_print
	make clean -C error_directive
	make run -C stringizing_operator
	make run -C ar
