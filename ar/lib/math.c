#include <stddef.h>

long sum(long *arr, size_t size) {
  int i;
  long ans = 0;
  for(i = 0; i < size; i++) {
    ans += arr[i];
  }
  return ans;
}
