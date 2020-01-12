#include <unistd.h>

#ifndef NUMBER
#define NUMBER 0
#endif
// If but 0, error: only zero initializers are allowed in section '.bss'
// Compiler does initialize zeros in bss section!
int num __attribute__ ((section (".bss"))) = NUMBER;

void test(void) {
  const char name[] = "Kenta\n";
  write(STDOUT_FILENO, name, sizeof(name));
  const char n_str[3] = {num+'0', '\n', '\0'};
  write(STDOUT_FILENO, n_str, sizeof(n_str));
  _exit(0);
}
