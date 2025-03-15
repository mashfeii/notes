#include <iostream>
#include <string>
#include <utility>

int main() {
  std::string x = "abc";
  std::string &&y = std::move(x);
  std::string &&z = std::move(y);
  std::cout << "x: " << x << '\n' << "y: " << y << '\n' << "z: " << z << '\n';

  std::string t = std::move(x);

  std::cout << "x: " << x << '\n'
            << "y: " << y << '\n'
            << "z: " << z << '\n'
            << "t: " << t << '\n';
}
