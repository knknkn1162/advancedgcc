#include <stddef.h>
#include <unistd.h>

extern void (*__init_array_start []) (void) __attribute__((weak));
extern void (*__init_array_end []) (void) __attribute__((weak));
extern void (*__fini_array_start []) (void) __attribute__((weak));
extern void (*__fini_array_end []) (void) __attribute__((weak));
int main(void);

void _start(void) {
  const size_t size = __init_array_end - __init_array_start;
  size_t i;
  int res;

  // _init() // constructor(.ctor)?
  // .init_array section
  for (i = 0; i < size; i++)
    (*__init_array_start [i]) ();

  res = main();

  // .fini_array section
  i = __fini_array_end - __fini_array_start;
  while (i-- > 0)
    (*__fini_array_start [i]) ();
  // _fini() // destructor(.dtor)?

  _exit(res);
}
