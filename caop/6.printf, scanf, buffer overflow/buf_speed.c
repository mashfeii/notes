#include <stdio.h>
#include <time.h>

void print(unsigned num) {
  clock_t t;
  t = clock();

  for (unsigned i = 0; i != num; ++i) {
    printf("hello, num %u", i);
  }

  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC;
  fprintf(stderr, "%f seconds\n", time_taken);
}

int main() {
  unsigned iterations = 1000000;
  // NOTE: first, the printf with buffer (approximately 4096 chars)
  print(iterations);
  setbuf(stdout, NULL);
  // NOTE: second, without buffer (100 times slower)
  print(iterations);
  return 0;
}
