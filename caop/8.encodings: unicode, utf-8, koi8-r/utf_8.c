#include <stdio.h>

int main() {
  char str[] = {0xF0, 0xD2, 0xC9, 0xD7, 0xC5, 0xD4, '\0'};
  for (int i = 0; i != sizeof(str); ++i) {
    str[i] &= 0x7f;  // example of converting to utf-8/ascii symbols
  }
  printf("%s\n", str);
  printf("%lu", sizeof(str));
}
