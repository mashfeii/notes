#include <iostream>
#include <utility>
#include <vector>

template <typename T> struct Debug { Debug() = delete; };

struct S {
  int x = 0;
};

template <typename Container>
// auto getElement(Container &container, size_t index)
//     -> decltype(container[index]) {
decltype(auto) getElement(Container &container, size_t index) {
  return container[index];
}

int main() {
  int x = 0;
  // int& y = x;
  // decltype(y) z = y;
  // decltype(x)&& t = std::move(x);
  // const decltype(&x) p = &x;
  // decltype(x++) u = x; // u = int&
  // ++u;
  // decltype(throw 1)* p = &x; // p = void*
  // decltype((x)) y = x; // y = int&
  // decltype(S().x) z = x; // z = int
  // ++y;

  std::vector<bool> v(5);
  getElement(v, 0) = 1;
}
