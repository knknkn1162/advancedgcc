#include <unistd.h>

void test(void) {
  const char name[] = "Kenta\n";
  write(STDOUT_FILENO, name, sizeof(name));
  _exit(0);
}
