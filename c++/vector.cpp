#include <iterator>
#include <memory>
#include <type_traits>
#include <utility>

template <typename T, typename Alloc = std::allocator<T>>
class vector {
 private:
  T* arr_;
  size_t sz_;
  size_t cap_;
  Alloc alloc_;
  using AllocTraits = std::allocator_traits<Alloc>;

  template <bool IsConst>

  class base_iterator {
   public:
    using pointer_type = std::conditional_t<IsConst, const T*, T*>;
    using reference_type = std::conditional_t<IsConst, const T&, T&>;
    using value_type = T;

    base_iterator(const base_iterator&) = default;
    base_iterator& operator=(const base_iterator&) = default;

    reference_type operator*() const { return *ptr; }
    pointer_type operator->() const { return ptr; }

    base_iterator& operator++() {
      ++ptr;
      return *this;
    }
    base_iterator operator++(int) {
      base_iterator copy = *this;
      ++ptr;
      return copy;
    }
    operator base_iterator<true>() const { return {ptr}; }

   private:
    pointer_type ptr;
    base_iterator(T* ptr) : ptr(ptr) {};
    friend class vector<T>;
  };

 public:
  using iterator = base_iterator<false>;
  using const_iterator = base_iterator<true>;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  vector& operator=(const vector& other) {
    Alloc newAlloc = AllocTraits::propagate_on_container_copy_assignment::value
                         ? other.alloc_
                         : alloc_;

    T* newArr = AllocTraits::allocate(newAlloc, other.cap_);
    size_t i = 0;
    try {
      for (; i != other.sz_; ++i) {
        AllocTraits::construct(newAlloc, newArr + i, other[i]);
      }
    } catch (...) {
      for (size_t j = 0; j != i; ++j) {
        AllocTraits::destroy(newAlloc, newArr + j);
      }
      AllocTraits::deallocate(newAlloc, newArr, other.cap_);

      alloc_ = newAlloc;
      arr_ = newArr;
      sz_ = other.sz_;
      cap_ = other.cap_;
    }
  }

  iterator begin() { return {arr_}; }
  iterator end() { return {arr_ + sz_}; }
  const_iterator begin() const { return {arr_}; }
  const_iterator end() const { return {arr_ + sz_}; }
  const_iterator cbegin() const { return {arr_}; }
  const_iterator cend() const { return {arr_ + sz_}; }

  void reserve(size_t newcap) {
    // Check that new capacity is bigger
    if (newcap <= cap_) {
      return;
    }
    // Alocate empty memory with new capacity
    T* newarr = AllocTraits::allocate(alloc_, newcap);
    size_t i = 0;
    try {
      for (; i != sz_; ++i) {
        // Try to construct each element from current array on new place
        AllocTraits::construct(alloc_, newarr + i,
                               std::move_if_noexcept(arr_[i]));
        // Function additionally checkes that object can be moved and copied(!)
      }
    } catch (...) {
      // If something goes wrong, remove all already constructed elements
      for (size_t j = 0; j != i; ++j) {
        AllocTraits::destroy(alloc_, newarr + j);
      }
      AllocTraits::deallocate(alloc_, newarr, newcap);
      throw;
    }

    // Destroy all (now their are previous) elements
    for (size_t i = 0; i != sz_; ++i) {
      AllocTraits::destroy(alloc_, arr_ + i);
    }
    // Free previous array's memory
    AllocTraits::deallocate(alloc_, arr_, cap_);

    arr_ = newarr;
    cap_ = newcap;
  }

  /*
   * Interesting case: vector.push_back(vector[3]);
   * To correctly handle such case, we should firstly move the element of last
   * position and only after that start working on reallocation
   */
  // template <typename... Args>
  // Universal reference take either lvalue or rvalue
  void emplace_back(auto&&... args) {
    if (sz_ == cap_) {
      reserve(cap_ > 0 ? cap_ * 2 : 1);
    }
    // new (arr_ + sz_) T(value);
    AllocTraits::construct(alloc_, arr_ + sz_,
                           std::forward<decltype(args)>(args)...);
    ++sz_;
  }
  void push_back(const T& value) { emplace_back(value); }
  void push_back(T&& value) { emplace_back(std::move(value)); }
};
