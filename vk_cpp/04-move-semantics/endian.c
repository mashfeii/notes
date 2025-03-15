#include <stdint.h>
#include <stdio.h>

int main() {
  uint16_t x = 0x0001;
  printf("%s-endian", (*(uint8_t *) &x ? "little" : "big"));
}
