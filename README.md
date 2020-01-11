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

For more details, see [the link](https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_10.html):

+ `$(CC) -c $(CPPFLAGS) $(CFLAGS)` in C -> object file

+ `$(CXX) -c $(CPPFLAGS) $(CXXFLAGS)` in C++ -> object file

+ `$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) -o $@` in C -> exec file

+ `$(AS) $(ASFLAGS)` in asm

+ `$(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@` in linker. see `ar` directory.

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
