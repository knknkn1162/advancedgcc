#include <unistd.h>

#define ENTRY __attribute__((section(".text.init")))

// dummy(NOT entrypoint)
int test1(int a) {
  int b = a*10;
  return b;
}

int ENTRY _start(int argc, char* argv[]) {
  const char str[] = "test\n";
  write(STDOUT_FILENO, str, sizeof(str));
  return test1(5);
}
