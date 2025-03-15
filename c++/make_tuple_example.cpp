#include <iostream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

// template <typename... Types>
// auto make_tuple(Types&&... types) -> tuple<std::decay_t<Types>...> {
//   return {std::forward<Types>(args)...};
// }

// template <typename... Types>
// auto tie(Types&... types) -> std::tuple<Types&...> {
//   return {types...};
// }

template <typename... Ts>
struct X {
  std::tuple<const Ts&...> values;
  explicit X(const Ts&... values): values(std::make_tuple(values...)) {}
};

int main() {
  int i = 42;
  auto s = std::string("universe");
  auto x = X<int, std::string>(i, s);

  std::cout << "i = " << std::get<0>(x.values) << '\n';
  std::cout << "s = " << std::get<1>(x.values) << '\n';
}
