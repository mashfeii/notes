#include <string>

using std::string;

template <typename T> struct S {
  string data;
  S(const string &data) : data(data) {}       // for lvalue - copy
  S(string &&data) : data(std::move(data)) {} // for rvalue - move

  void push_back(const T &value); // default variable
  void push_back(T &&value) {     // temporary variable
    // ...
    new (ptr) T(std::move(value));
    // instead of creating by copy, we move the value
  }
};

// For types, that supports move-semantics, such swap will work in constant time
template <typename T> void swap(T &x, T &y) {
  T temp = std::move(x);
  x = std::move(y);
  y = std::move(temp);
}
