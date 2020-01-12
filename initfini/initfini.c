#include <unistd.h>

static void init () {
  const char msg[] = "init_array\n";
  write(STDOUT_FILENO, msg, sizeof(msg));
}

static void fini () {
  const char msg[] = "fini_array\n";
  write(STDOUT_FILENO, msg, sizeof(msg));
}

static void (*const init_array []) ()
  __attribute__ ((section(".init_array"), aligned(sizeof(void *))))
  = { init };

static void (*const fini_array []) ()
  __attribute__ ((section (".fini_array"), aligned (sizeof (void *))))
  = { fini };
