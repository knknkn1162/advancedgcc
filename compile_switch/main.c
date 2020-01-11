#include <stdio.h>

#if DEBUG
#include "print.h"
#define hello_world(name) print_world(name)
#else
#define hello_world(name) do {} while(0)
#endif

int main(void) {
  printf("start -> \n");
  hello_world("Kenta");
  printf("<- end \n");
}
