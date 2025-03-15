#include "stdio.h"

int multiply_add(int, int);

int main(void) {
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);

  int c = multiply_add(a, b);
  printf("%d", c);

  return 0;
}
