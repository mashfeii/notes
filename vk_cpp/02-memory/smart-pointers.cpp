#include <iostream>
#include <memory>

void foo(std::shared_ptr<char[]> ptr_copy) {
  std::cout << ptr_copy.use_count() << std::endl;
}

int main() {
  {
    int *arr = new int[26]; // simple pointer to array
    std::unique_ptr<int[]> ptr(new int[33]);
    // std::cout << sizeof(ptr); // 8, as default pointer
  }

  {
    std::shared_ptr<char[]> ptr1(new char[26]);
    std::cout << ptr1.use_count() << std::endl;
    auto ptr2(ptr1);
    std::cout << ptr2.use_count() << std::endl;
    foo(ptr2);
  }
}
