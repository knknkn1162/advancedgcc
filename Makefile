SUBDIRS = ar\
		  compile_switch\
		  error_directive\
		  freestanding_print\
		  linker_script\
		  stringizing_operator

.PHONY: all clean run $(SUBDIRS)

all: clean build

build:
	$(foreach dir, $(SUBDIRS), \
	  echo "+ build $(dir)";\
	  make -C $(dir);\
	)

run: build
	$(foreach dir, $(SUBDIRS), \
	  echo "+ run $(dir)";\
	  make -C $(dir) run;\
	)

clean:
	$(RM) *.o *.a
	$(foreach dir, $(SUBDIRS), \
	  echo "+ clean $(dir)";\
	  make -C $(dir) clean;\
	)
