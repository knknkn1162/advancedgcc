//#include "cdtor.h"
#include <stdint.h>
#include <stdio.h>

static inline uint64_t rdtsc(void)
{
	unsigned int low, high;

	asm volatile("rdtsc" : "=a" (low), "=d" (high));

	return low | ((uint64_t)high) << 32;
}

uint64_t duration = 0;

static void __attribute__((constructor)) init(void) {
  duration = rdtsc();
}

static void __attribute__((destructor)) fini(void) {
  uint64_t end = rdtsc();
  duration = end - duration;
  printf("time: %lu\n", duration);
}
