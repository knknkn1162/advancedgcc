# using static library

+ The order of `-L` and `-l` option is important. `-l` option must be followed by objects:

```sh
gcc -Llib -lsample program.o -o program
/usr/bin/ld: main.o: in function `main':
main.c:(.text+0x77): undefined reference to `sum'
collect2: error: ld returned 1 exit status
make: *** [Makefile:13: program] Error 1
```

```sh
# no problem
gcc -Llib  program.o  -lsample -o program
```

+ check the implicit rule in linking.
