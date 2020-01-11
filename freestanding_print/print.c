#include <unistd.h> // write
#include <stdarg.h> // va_start, va_end
#include "mini-printf.h"
#define BUFSIZ 512

size_t strlen(const char *buf) {
  int len;
  for(len = 0; buf[len]; len++) ;
  return len;
}

int printf(const char* fmt, ...)
{
  char buf[BUFSIZ] = { '\0' };
  va_list ap;
  int len;
  va_start(ap, fmt);
  vsnprintf(buf, BUFSIZ, fmt, ap);
  va_end(ap);

  len = strlen(buf);
  write(STDOUT_FILENO, buf, BUFSIZ);
  return (int)len + 1;
}

void hello_world(const char* name) {
  printf("hello, %s\n", name);
  return;
}
