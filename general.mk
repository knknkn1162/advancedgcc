# you should prepare SUBDIR
.PHONY: run clean
run:
	./program

clean:
ifdef SUBDIR
	-make -C $(SUBDIR) clean
endif
	$(RM) program *.o *.a $(CLEAN_FILES)
