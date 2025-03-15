## `this` Pointer

By definition, `this` is a constant pointer. It points to the instance for which method was called.
For the class `C` its type `C *const`
By definition, `member` and `this -> member` are semantically equal
The pointer to instance gets passed to the function _as very first hidden parameter_!

> [!NOTE]- Summary:
> __If__ a member function does not really modify the state of the instance then it is good practice to make it __"constant"__
> Such a function may be applied to both _non-constant_ and _constant_ instances; therefore it is more "generic"

## Delete & Default pecifiers for Member Functions 
Non-copyable objects: add copy constructor & copy assignment explicitly making them __private__ and declare the default constructor: 
```cpp 
class nonCopyable {
public:
  nonCopyable() {} // nonCopyable() = default;
  nonCopyable(const nonCopyable&) = delete;
  nonCopyable &operator=(const nonCopyable&) = delete;
private:
  nonCopyable(const nonCopyable&);
  nonCopyable &operator=(const nonCopyable &);
  // ..other members
```
In general this code will cause the __linker error__.

> [!NOTE]- Advantages:
> - No need to remember the rules of automatic generation.
> - No need to provide function bodies.
> - An attempt to call to a function marked as delete causes compile-time error.

## Function: Declarations & Definitions 
- `int f(int x) { ... }` function __definition__: the full function including the signature and the body
- `int f(int x);` function __declaration__: only signature

## Dynamic Cast 
`dynamic_cast<T>(v), static_cast<T>(v)`
- Value `v` is converted to a value of type `T`
- Type `T` is a pointer/reference type 
- `v` is a pointer/reference to an object of a class type 
- `static_cast` does not perform run-time checks

`const_cast<T>(v)`
- Is used to drop "constness"
- No real action are performed

`reinterpret_cast<T>(v)`
- Is used to change the interpretation of the binary image of an object.
- No real actions are performed 
- No run-time checks are performed 

```cpp 
Base* pd = new Derived();
...
const std::type_info &info = typeid(pd);
```
`typeid` return the reference to an instance of the library-defined `type_info` class.
The instance contains information about _dynamic type_ of the operand.


