#include <exception>
#include <iostream>
#include <string>

class A {
 private:
  int* arr_;

  void init_() { throw std::exception(); }

 public:
  A() : arr_(new int[1024]) {
    std::cout << "A()" << std::endl;
    init_();
  }
  ~A() {
    std::cout << "~A()" << std::endl;
    delete[] arr_;
    throw std::exception();
  }
};

int main() {
  try {
    A a;
  } catch (std::exception&) {
    std::cout << "Exception caught" << std::endl;
  }
}
