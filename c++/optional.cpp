#include <algorithm>
#include <type_traits>

template <typename T>
class optional {
private:
  char val[sizeof(T)];
  bool initialized = false;
public:
  optional(const T& new_val): initialized(true) {
    new (val) T(new_val);
  }
  optional() {}
  ~optional() {
    if (initialized) {
      reinterpret_cast<T*>(val)->T();
    }
  }
  bool has_value() const {
    return initialized;
  }
  operator bool() const {
    return initialized;
  }
  T& operator*() {
    return reinterpret_cast<T&>(*val);
  }
  const T& operator*() const & {
    return reinterpret_cast<const T&>(*val);
  }
  T&& operator*() & {
    return reinterpret_cast<T&&>(*val);
  }
  const T&& operator*() const && {
    return reinterpret_cast<const T&&>(*val);
  }

  // since C++23 - explicitly taken self (same as in python, reference to
  // current instance)
  // template <typename Self>
  decltype(auto) value(this auto&& self) {
    if (!initialized) {
      throw std::bad_optional_access();
    }
    using DesiredType = decltype(std::forward_like<decltype(self)>(std::declval<T>()));
    return reinterpret_cast<DesiredType>(self.val);
  }

  const T& value_or(const T& other) const {
    return initialized ? reinterpret_cast<T&>(*val) : other;
  }
};
