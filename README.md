# AdvanceGCC

This is the collection of confusing but common tips in C-lang, `gcc`, `make` and `ld`.

# Preparations && Build

```sh
# version: 9.2.0
docker run -it -v $(pwd):/home/me -w /home/me --rm gcc
# inside docker
make
# When you run all sample programs..
make run
```

If you want to erase this, `make clean`.

# tips

## ar

## stdin_compile

+ .ONESHELL .. This enables here document in Makefile.

+ gcc compile from stdin .. see https://www15.big.or.jp/~yamamori/sun/gcc/stdin.html.


## Makefile

### Reference

+ https://qiita.com/knknkn1162/items/c67ae7c2ef71a713adf8 : How to use `readelf`, `hexdump` and `ld`
+ https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_10.html : implicit rule(official)
+ https://goth-wrist-cut.hatenadiary.org/entry/20080317/1205769293 : examples of `patsubst`, `foreach` and `shell`

### Implicit rules

For more details, see [the link](https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_10.html):

+ `$(CC) -c $(CPPFLAGS) $(CFLAGS)` in C -> object file

+ `$(CXX) -c $(CPPFLAGS) $(CXXFLAGS)` in C++ -> object file

+ `$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) -o $@` in C -> exec file

+ `$(AS) $(ASFLAGS)` in asm

+ `$(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@` in linker. The `ar` directory uses implicit rule on link

### PHONY

```make
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

## Misc

+ If docker container was freezed, type Ctrl-C.
