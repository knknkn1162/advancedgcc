#ifdef NOSTDLIB
#define STDOUT_FILENO 1
long int syscall (long int __sysno, ...);
#else
#include <unistd.h>
#endif

#include <sys/syscall.h>

void _start(void) {
  const char msg[] = "Hello world!\n";
  syscall(SYS_write, STDOUT_FILENO, msg, sizeof(msg));
  syscall(SYS_exit, 0);
}
