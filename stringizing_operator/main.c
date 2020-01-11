#include <stdio.h>

#define STR ans
#define PRINT_STR() STRING_PRINT(STR)
#define STRING_PRINT(a) printf("hello, " #a ": %d\n", a());

int ans(void) {
  return 100;
}
int main(void) {
  printf("start -> \n");
  STRING_PRINT(ans);
  PRINT_STR(); // hello, STR: 100; cannot expand STR!
  printf("<- end \n");
}
