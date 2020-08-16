#include <stdio.h>

int main(void) {
    char str[] = "hello world\n";
    int len = 5;
    printf("%.*s\n", len, str);
    return 0;
}
