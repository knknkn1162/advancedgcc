#include <stdio.h>
#include "math.h"
#include "string.h"

#define SIZE_MAX 100
 
int main(void) {
  const char *argv[] = {
    "hello",
    "world",
    "!",
  };
  size_t size = sizeof(argv)/sizeof(argv[0]);
  long len[SIZE_MAX];
  int i;
  for(i = 0; i < size; i++) {
    len[i] = strlen(argv[i]);
  }

  printf("%ld\n", sum(len, size));
  return 0;
}
