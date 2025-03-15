#include <iostream>
#include <tuple>

int main() {
  std::tuple<int, double, char> t{1, 2.0, 'a'};

  auto d = std::get<1>(std::move(t));
  d = 3.14;

  std::cout << std::get<1>(t) << '\n';

  // Structured bindings (C++17)
  auto&& [x, y, z] = std::move(t);
  z = 'b';

  // Map traversing
  // for (const auto& [key, value]: map) {}

  std::cout << std::get<2>(t);
}
