#include <stdint.h>
#include <stdio.h>

// __attribute__((constructor/destructor)) don't need declaration because this is required on the stage of linking process
extern uint64_t duration;
#define COUNT_MAX (1L<<26)

int main() {
  uint64_t i = 0;
  uint64_t inc = 0;
  printf("tdtsc start: %lu\n", duration);

  // take some time..
  for(i = 0; i < COUNT_MAX; i++) inc++;
  return 0;
}

