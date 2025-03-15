#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void bye() {
  printf("Bye!\n");
}

int main() {
  atexit(bye);

  printf("Hello from main()");

  // return 1;
  _exit(0);
}
