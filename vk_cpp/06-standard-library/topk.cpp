#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::vector<int32_t> arr = {10, 4, 8, 2, 3, 13, 9, 7};
  {
    const int k = 3;
    std::sort(std::begin(arr), std::end(arr));
    std::vector<int32_t> res;
    res.reserve(k);

    auto begin = arr.rbegin();
    auto end = arr.rend();

    while (res.size() != k && begin != end) {
      res.push_back(*begin);
      ++begin;
    }
    for (auto num : res) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
  {
    const int k = 3;
    std::priority_queue<int32_t, std::vector<int32_t>, std::greater<int32_t>>
        pq;
    for (auto num : arr) {
      pq.push(num);
      if (pq.size() > k) {
        pq.pop();
      }
    }

    std::vector<int32_t> res;
    res.reserve(k);

    while (!pq.empty()) {
      res.push_back(pq.top());
      pq.pop();
    }

    std::reverse(res.begin(), res.end());

    for (auto num : res) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
}
