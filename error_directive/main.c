#include <stdio.h>
#include "print.h"

#if CONDITION==1
#define DEBUG
#else
#error "CONDITION macro is not true. See ~"
#endif

int main(void) {
  printf("start -> \n");
#ifdef DEBUG
  print_world("Kenta");
#endif
  printf("<- end \n");
}
