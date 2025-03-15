// #include <algorithm>
#include <iostream>
#include <vector>

void abs(int* num) {
  if (*num < 0)
    *num = -*num;
}
void abs_ref(int& num) {
  if (num < 0)
    num = -num;
}

using func_t = void (*)(int*);
extern "C" void for_each(int* arr, int size, func_t func);

int main() {
  std::vector<int> nums;
  int num;
  while (std::cin >> num) {
    nums.push_back(num);
  }

  // std::cout << sizeof(nums.data());

  // std::for_each(nums.begin(), nums.end(), abs_ref);
  for_each(nums.data(), nums.size(), abs);


  for (int i : nums) {
    std::cout << i << " ";
  }
}
