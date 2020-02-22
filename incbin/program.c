#include <stdio.h>
#include <stdint.h>

extern char _payload_start;
typedef int (*func_t)(uintptr_t, uintptr_t);


int main(int argc, char* argv[]) {
  func_t fn = (func_t)&_payload_start;
  int res = fn((uintptr_t)argc, (uintptr_t)argv);
  printf("%d\n", res);
  return 0;
}
