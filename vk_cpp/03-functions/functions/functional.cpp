#include <functional>
#include <iostream>
#include <vector>
void moveLeft(int& x, int& y) {
  std::cout << "Move left (" << x << ", " << y << ")" << std::endl;
  --x;
}

class RightMover {
 public:
  void operator()(int& x, int& y) {
    std::cout << "RightMover (" << x << ", " << y << ")" << std::endl;
    ++x;
  }
};

using MoverType = std::function<void(int&, int&)>;

int main() {
  auto top_mover = [](int& x, int& y) -> void { ++y; };
  RightMover right_mover;

  std::vector<MoverType> movers = {moveLeft, top_mover, right_mover};

  int x = 0;
  int y = 0;
  for (const auto& mover : movers) {
    mover(x, y);
  }
}
