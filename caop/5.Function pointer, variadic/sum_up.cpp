#include <cstdarg>
#include <iostream>
extern "C" int my_sum_up(int count, ...);

int sum_up(int count, ...) {
  va_list args;
  va_start(args, count);

  int accum = 0;
  for (int i = 0; i != count; ++i) {
    accum += va_arg(args, int);
  }
  va_end(args);

  return accum;
}

int main() {
  std::cout << my_sum_up(5, 1, 2, 3, 4, 5) << std::endl;
}
