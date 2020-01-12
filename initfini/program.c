#include <unistd.h>

int main(void) {
  const char msg[] = "THIS is the main program!\n";
  write(STDOUT_FILENO, msg, sizeof(msg));
  return 0;
}
