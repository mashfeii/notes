#include <iostream>

class string {
private:
  char *arr;
  size_t sz;
  size_t cap;

public:
  // Move contructor from rvalue-reference
  string(string &&other) : arr(other.arr), sz(other.sz), cap(other.cap) {
    other.arr = nullptr; // For avoiding double delition
    other.sz = other.cap = 0;
  }
  string &operator=(string &&other) {
    delete[] arr; // First, delete own array

    arr = other.arr; // Assign from other
    other.arr = nullptr; // Make other's object empty

    sz = other.sz;
    other.sz = 0;

    cap = other.cap;
    other.cap = 0;

    return *this;
  }
};

int main() {}
