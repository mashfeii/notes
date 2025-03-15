#include <type_traits>
#include <utility>

template <typename T>
struct is_lvalue_referecne: std::false_type {};

template <typename T>
struct is_lvalue_reference<T&>: std::true_type {};

template <typename T>
T&& forward(std::remove_reference_t<T>& value) {
  return static_cast<T&&>(value);
}
/* For parameter type `T&&`
 * 1. Args = lvalue = int&
 * typeof(args) = int&
 * T = int&
 * typeof(value) = int&
 * 2. Args = rvalue = int
 * typeof(args) = int&&
 * T = int
 * T&& = int&& (for parameter `T&`)
 */

template <typename T>
// move should accept both lvalue and rvalue, so `T&&` is parameter type
// (universal reference)
std::remove_reference_t<T>&& move(T&& value) {
  // move must(!) return rvalue
  return static_cast<std::remove_reference_t<T>&&>(value);
}

template <typename T>
struct allocator {
  T* allocate(std::size_t count) { return operator new(count * sizeof(T)); }
  void deallocate(T* ptr, std::size_t) { operator delete(ptr); }

  template <typename U, typename... Args>
  void construct(U* ptr, Args&&... args) {
    new (ptr) U(std::forward<Args>(args)...);
  }

  template <typename U>
  void destroy(U* ptr) {
    ptr->~U();
  }
};
