#include <stdio.h>

#define STRING_PRINT(a) printf("hello, " #a ": %d\n", a());

int ans(void) {
  return 100;
}
int main(void) {
  printf("start -> \n");
  STRING_PRINT(ans);
  printf("<- end \n");
}
