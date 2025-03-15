#include <stdio.h>
#include <unistd.h>

enum {
  PERCENT = 5,
  LEN = 200 / PERCENT,
};

void print(unsigned p) {
  int p_ = p / PERCENT;

  // NOTE: rewrite the text (return the cursor to the line start)
  printf("\r[");

  for (int i = 0; i != p_; ++i) {
    printf("-");
  }
  printf(">");

  for (int i = p_; i != LEN; ++i) {
    printf(" ");
  }

  // here, 4 defines the 'size' of output
  printf("]%4u%%", p);

  // NOTE: clearing the buffer (std::endl)
  fflush(stdout);
}

void f() {
  sleep(1);
}

int main() {
  for (int i = 0; i != LEN + 1; ++i) {
    print(i * PERCENT);
    f();
  }
  printf("\n");

  return 0;
}
