# AdvanceGCC

# preparations && build

```sh
docker run -it -v $(pwd):/home/me -w /home/me --rm gcc
# inside docker
make
```

If you want to erase this, `make clean`.

# general

## Makefile

### Implicit rule

+ `$(CC) -c $(CPPFLAGS) $(CFLAGS)` in C

+ `$(CXX) -c $(CPPFLAGS) $(CXXFLAGS)` in C++

+ `$(AS) $(ASFLAGS)` in asm

Note) $(LD) has no implicit rule!

### PHONY

```
# Makefile
compile_switch:
	make -C compile_switch
```

```sh
make compile_switch
make: 'compile_switch' is up to date.
```

This is because `compile_switch` directory has been already created before `make compile_swtich`.

To avoid this, write `.PHONY compile_switch` and you can fully compile this.

## misc

+ If docker container is freezed, type Ctrl-C. 

# detailed.

For detailed information on each directory, check README.md in the directory.
