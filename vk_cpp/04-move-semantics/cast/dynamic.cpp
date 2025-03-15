#include <iostream>

struct A {
  virtual void help() { std::cout << "A help" << std::endl; }
};
struct B : A {
  void help() override { std::cout << "B help" << std::endl; }
};

void foo(A* a) {
  auto b = dynamic_cast<B*>(a);
  b->help();
}

int main() {
  A* a = new A;
  foo(a);
}
