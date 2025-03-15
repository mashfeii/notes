#include "stdio.h"
#include "string.h"

int main() {
  // #BUG: both string are in stack, so if whe overflow one, we will rewrite the other
  char input[9];
  char password[9] = "password";

  scanf("%s", input);

  if (strcmp(input, password) == 0) {
    printf("Accessed\n");
  } else {
    printf("Denided\n");
  }
}
