#include <iostream>
#include <vector>

struct Triangle {
  int leg1;
  int leg2;
  int hypot;
};

extern "C" void compute_hypotenuse(Triangle* arr, int size);

int main() {
  std::vector<Triangle> triangles;
  int leg1, leg2;

  while (std::cin >> leg1 >> leg2) {
    triangles.push_back({leg1, leg2, 0});
  }
  compute_hypotenuse(triangles.data(), triangles.size());
  for (auto&& tr : triangles) {
    std::cout << tr.leg1 << " " << tr.leg2 << ' ' << tr.hypot << '\n';
  }
}
