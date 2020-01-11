#include <unistd.h>
#include "print.h"

void _start(void) {
  hello_world("Kenta");
  _exit(0);
}
