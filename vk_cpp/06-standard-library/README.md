#### Allocators

The main aim - to allocate and free memory

```cpp
template <typename T>
class allocator {
public:
    using value_type = T;
    using pointer = T*;
    using size_type = size_t;

    pointer allocate(size_type count);
    void deallocate(pointer ptr, size_type count);
};
```

#### `std::vector` - dynamic container

```cpp
template <typename T, typename Alloc = std::allocator<T>>
class vector {
public:
    using size_type = size_t;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using allocator_type = Alloc;

    explicit vector(size_type count);
    vector(size_type count, const value_type& defaultValue);
    vector(initializer_list<value_type> init);

    iterator begin() noexcept; // end()
    reverse_iterator rbegin() noexcept; // rend()
    const_iterator cbegin() const noexcept; // cend()
    const_reverse_iterator crbegin() const noexcept; // crend()

    void reserve(size_type count); // allocates memory, increase capacity
};
```

#### `std::deque`

Has the same interface as `std::vector`, but stores data not sequentially, but with blocks for n
elements

## Iterators

Object that allows to access elements of collection and managing iteration
Allows to implement common algorithms for work with containers

1. Input iterator (`operator*`, `operator++(int)`, `operator==`)
2. Forward iterator (contains both input and output iterators)
3. Bidirectional iterator (forward + `operator--`)
4. Random Access iterator (can be summed or subtracted with integer)
5. Output iterator (`operator*`, `operator++(int)`)

## Red-black trees

Binary search tree with additional byte for color in each node

1. Each node is either **black or red**
2. The **root** of the tree **is black**
3. Each **leaf** is **black**
4. If node - read, then both its children are black
5. For each node all paths from it to child leafs contain the same number of black nodes (black
   height)
