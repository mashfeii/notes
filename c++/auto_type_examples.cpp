#include <algorithm>
#include <type_traits>

template <typename T>
void f(T&& x) {}

template <typename Container>
void h(Container&& container) {
  // Such range-based loop can work with both rvalue and lvalue
  for (auto&& value : f(container)) {
  }
}

template <typename T>
auto g(T x) {
  return ++x;
}

// This example will be compiled, shows the order for `auto` and `templates`
// generating
template <typename T>
auto k(T x) {
  if constexpr(std::is_same<T, int>::value) {
    return 0;
    // return k(x); // CE, compiler avoids such unbouned recursion
  } else {
    return 1u;
  }
}

// Trailing return type
template <typename T>
auto move(T&& value) -> std::remove_reference_t<T>&& {
  return static_cast<std::remove_reference_t<T>&&>(value);
}

int main() {
  auto&& xx = g(1); // Broken reference
  // since C++11
  auto x = 5;
  auto& y = x;
  const auto& z = y;
  auto&& t = std::move(x);
  auto&& a = 0;
  int* p = &x;
  int* pp = new auto(5);
}
