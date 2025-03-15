#include <iostream>

struct S {
  int x = 0;
  S(int x): x(x) {
    std::cout << "Created" << std::endl;
  }
  S(const S& s): x(s.x) {
    std::cout << "Copy" << std::endl;
  }
  S(S&& s): x(s.x) {
    std::cout << "Move" << std::endl;
  }
  ~S() {
    std::cout << "Destroyed" << std::endl;
  }
};

S func() {
  S s = 1;
  return s; // NRVO - Return Value Optimization (значение создаётся в точке
  // возврата, без вызова дополнительных конструкторов)
}

int main() {
  // temporary materialization (материализация временного объекта - временные
  // объекты pure rvalue не помещаются в память, а просчитываются компилятором,
  // но для того, чтобы передать объект, его необходимо сохранить, поэтому, в
  // данном случае вызывается два конструктора)
  // S s = std::move(S(S(S(S(S(1))))));
  
  // S(S(S(S(S(1))))); // 1. Created
  // int x = S(0).x; // 1. Created
  
  S s = func(); // CVO (Нет вызова дополнительных конструкторов: значение из
  // prvalue сразу подставляется в переменную)
}
