# specify linker script

+ You can check default linker script by `ld --verbose`. See https://gist.github.com/knknkn1162/d7301e6a14d8a781bf6a61ceb7985e9c

+ If you want to specify entrypoint function name, write `ENTRY($func_name)` on linker script or `-e $func_name` in gcc option.

+ try `make NUM=4`. Compiler does initialize zeros in bss section!
