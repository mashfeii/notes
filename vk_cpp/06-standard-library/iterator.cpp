#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>

template <typename T>
class array_iterator {
  T* ptr;

 public:
  array_iterator(T* ptr) : ptr(ptr) {}
  T& operator*() { return *ptr; };
  T* operator->() { return ptr; }
  array_iterator& operator++() {
    ++ptr;
    return *this;
  }
  array_iterator operator++(int) {
    T* temp = *this;
    ++ptr;
    return temp;
  }
  array_iterator& operator--() {
    --ptr;
    return *this;
  }
  array_iterator operator--(int) {
    T* temp = *this;
    --ptr;
    return temp;
  }
  bool operator!=(const array_iterator& other) { return ptr != other.ptr; }
  bool operator==(const array_iterator& other) { return ptr == other.ptr; }
};

template <typename T, size_t N>
class myarray {
  T data[N];

 public:
  using iterator = array_iterator<T>;
  size_t size() const { return N; }

  T& operator[](size_t i) { return data[i]; }
  iterator begin() { return {data}; }
  iterator end() { return {data + N}; }
};

int main() {
  myarray<int32_t, 32> arr;
  for (size_t i = 0; i != arr.size(); ++i) {
    arr[i] = arr.size() - i;
  }

  std::cout << std::accumulate(arr.begin(), arr.end(), 0) << std::endl;

  for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
    std::cout << *iter << " ";
  }
}
