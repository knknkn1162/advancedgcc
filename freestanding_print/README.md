+ When [freestanding](https://ja.wikipedia.org/wiki/%E3%83%95%E3%83%AA%E3%83%BC%E3%82%B9%E3%82%BF%E3%83%B3%E3%83%87%E3%82%A3%E3%83%B3%E3%82%B0%E7%92%B0%E5%A2%83) environment, you have to implement printf by hand. We use [mludvig/mini-printf](https://github.com/mludvig/mini-printf) to print "hello $(name)`.

# TODO

go though `__libc_write`, `__libc_(enable|disable)_asynccancel` and `__libc_multiple_threads` (Is this related with `--disable-threads` gcc build option?)

```
# readelf -s ./program | grep " _"
    11: 000000000040118a    96 FUNC    LOCAL  DEFAULT    2 _putc
    12: 00000000004011ea   170 FUNC    LOCAL  DEFAULT    2 _puts
    16: 0000000000401860   153 FUNC    WEAK   HIDDEN     2 __write
    18: 0000000000401960    89 FUNC    GLOBAL HIDDEN     2 __libc_disable_asynccance
    19: 0000000000401800    88 FUNC    WEAK   DEFAULT    2 _Exit
    21: 00000000004017e2    24 FUNC    GLOBAL DEFAULT    2 _start
    22: 0000000000000000     4 TLS     GLOBAL HIDDEN     5 __libc_errno
    23: 0000000000404000     0 NOTYPE  GLOBAL DEFAULT    6 __bss_start
    25: 0000000000401900    86 FUNC    GLOBAL HIDDEN     2 __libc_enable_asynccancel
    26: 0000000000404000     4 OBJECT  GLOBAL HIDDEN     6 __libc_multiple_threads
    28: 0000000000404000     0 NOTYPE  GLOBAL DEFAULT    6 _edata
    29: 0000000000404008     0 NOTYPE  GLOBAL DEFAULT    6 _end
    31: 0000000000401800    88 FUNC    GLOBAL HIDDEN     2 _exit
    33: 0000000000401860   153 FUNC    GLOBAL HIDDEN     2 __libc_write
```
