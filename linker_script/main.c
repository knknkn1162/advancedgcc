#include <unistd.h>

void _start(void) {
  const char name[] = "Kenta\n";
  write(STDOUT_FILENO, name, sizeof(name));
  _exit(0);
}
