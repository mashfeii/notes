#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  pid_t p = getpid();
  printf("%u\n", p);

  while (1) {
    malloc(0);
  }
}
