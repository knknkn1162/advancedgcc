#include <unistd.h>

#define ENTRY __attribute__((section(".text.init")))

// dummy(NOT entrypoint)
int test1(int a) {
  int b = a*10;
  return b;
}

static char sample[] = "sample\n";

int ENTRY _start(int argc, char* argv[]) {
  const char str[] = "testtest\n";
  write(STDOUT_FILENO, str, sizeof(str));
  // TODO: this str does not print!
  write(STDOUT_FILENO, sample, sizeof(sample));
  return 0;
}
