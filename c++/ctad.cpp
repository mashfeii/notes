#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
struct Debug {
  Debug() = delete;
};

template <typename T>
struct vector {
  template <typename Iter>
  vector(Iter, Iter) {}
};

// // Explicit template deduction guides
// template <typename Iter>
// vector(Iter, Iter) -> vector<typename std::iterator_traits<Iter>::value_type>;

struct A {};
struct B {};

template <typename T, typename U>
struct S: T, U {};

int main() {
  S s {A(), B()};
  std::vector v = {1, 2, 3, 4, 5};
  // Vector with iterators on vector int
  // vector v2(v.begin(), v.end()); // std::vector<gnu__cxx::normal_iterator>
  // std::vector v2(v.begin(), v.end()); // std::vector<int>

  // Debug<decltype(v2)>();
}
