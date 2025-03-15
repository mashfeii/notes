#include <iostream>
#include <ostream>
#include <string>

class Dummy {
 public:
  std::string data_;

  Dummy() = default;
  Dummy(const Dummy& rhs) : data_(rhs.data_) {
    std::cout << "Dummy copy constructor" << std::endl;
  }
};

void foo(Dummy& rhs) {
  std::cout << "Passing by reference" << std::endl;
}

void boo(Dummy rhs) {
  std::cout << "Passing by value" << std::endl;
}

int main() {
  Dummy obj;
  foo(obj);
  boo(obj);

  int cnt1 = 0;
  int cnt2 = 0;

  int* ptr1 = &cnt1;
  int** ptr2 = &ptr1;

  const int* cptr1 = &cnt2; // read from right to left: pointer to constant variable
  int* const cptr2 = &cnt2; // constant pointer to normal variable
  const int* const cptr3 = &cnt2; // constant pointer to constant variable

  // ++*cptr1; // pointer to constant value
  ++*cptr2;
}
