If you use `error` or `warn` directive, invalid macro condition can be stopped in compilation.

```sh
$ make
gcc -DCONDITION=1   -c -o print.o print.c
gcc -DCONDITION=1   -c -o main.o main.c
gcc  -o program print.o main.o
# if you make the `CONDITION` macro invalid
$ make DEBUG=
gcc    -c -o print.o print.c
gcc    -c -o main.o main.c
main.c:7:2: error: "CONDITION macro is not true. See ~"
#error "CONDITION macro is not true. See ~"
 ^
1 error generated.
make: *** [main.o] Error 1
```
<Paste>
