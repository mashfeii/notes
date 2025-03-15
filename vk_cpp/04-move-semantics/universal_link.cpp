#include <iostream>

template <typename T>
void f(const T&& arg) {
  std::cout << "const rvalue-reference" << std::endl;
}
template <typename T>
void f(T&& arg) {
  std::cout << "universal reference" << std::endl;
}
template <typename T>
void f(const T& arg) {
  std::cout << "const l-value reference" << std::endl;
}

int main() {
  int x = 0;
  int& y = x;
  f(x);
  f(y);
  f(std::move(x));
  f(std::move(y));
}
