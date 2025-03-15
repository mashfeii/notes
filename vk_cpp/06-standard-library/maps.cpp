#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
  std::map<std::string, int32_t> counter;
  std::vector<std::string> words = {"let", "it", "be", "let", "let", "it"};

  for (const auto& word : words) {
    std::map<std::string, int32_t>::iterator it = counter.find(word);

    if (it == counter.end()) {
      counter[word] = 0;
    }
    counter[word] += 1;
  }

  auto begin = counter.begin();
  auto end = counter.end();

  while (begin != end) {
    std::cout << "key = " << begin->first << ", value=" << begin->second
              << '\n';
    ++begin;
  }
}
