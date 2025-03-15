#include <iostream>

extern "C" int multiply_add(int, int);

int main() {
  int a, b;

  std::cin >> a;
  std::cin >> b;

  int c = multiply_add(a, b);
  std::cout << c;
}
