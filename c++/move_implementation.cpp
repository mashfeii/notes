// naivde implementation of std::move - explicit rvalue cast
template <typename T> T &&move(T &x) { return static_cast<T &&>(x); }
