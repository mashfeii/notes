#include <iostream>

template <typename T> class Optional {
public:
  Optional() = default;
  Optional(const Optional &) { std::cout << "A" << std::endl; }
  // Not universal, but only rvalue reference
  template <typename U> Optional(Optional<U> &&) {
    std::cout << "B" << std::endl;
  }
  // Universal link, should be in format `T&&` nothing else
  template <typename U> Optional(U &&) { std::cout << "C" << std::endl; }
};

int main() {
  Optional<int> a;
  Optional<int> b(a);
  /*
   * A - : a is not const
   * B - : B looks for rvalue only
   * C + : a transforms to `Optional<int>` - lvalue reference
   */
}
