#include <iostream>
class A {
  virtual void help();
};

class B : public A {
  void help() override;
};

class C : public A {
  void help() override;
};

int main() {
  A* a = new B;
  std::cout << &a;
  C* c = dynamic_cast<C*>(a);
}
