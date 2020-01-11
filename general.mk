# you should prepare SUBDIR
ifndef SUBDIR
  SUBDIR=dummy
endif

.PHONY: run clean
run:
	./program

clean:
	-make -C $(SUBDIR) clean
	$(RM) program *.o
