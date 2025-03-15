> __Syntax__: a set of rules that regulate __the structure__ of programs and their part (constructs)

> __Semantics__: the __meaning__ of the constructs
>  - Static semantics: how programs get compiled
>  - Dynamic semantics: how programs get executed.

Each C/C++ program uses three kinds of memory:
- Program
- Dynamic memory ("Heap")
- Stack

__Type__ (of an object/entity) is:
- A set of __values__ that an object of the type can have
- A set of __operators__ on object of that type
- A set of __relationships__ between the type and other types

### C++ Types & Type Specifiers 
__Predefined__ (language-defined) 
- Integers 
- Reals (floats & doubles) 
- Characters 

__User-defined types__ 
- Classes 
- Enumerations 

__"Modified" types__
- Constant types 
- Pointer types 
- Reference types 
- Function types 
- Arrays

### Structured binding 
```cpp 
int a[2] = { 1, 2 };
auto [ x, y ] = a;
auto &[ xr, yr ] = a;

struct S {
  int x;
  const double y;
};
S f();

const auto [ x, y ] = f(); // Deconstruction 
```

### for-range
```cpp
vector<int> v = {0, 1, 2, 3};
for (const int& i : v) 
  cout << i << " ";
for (int n : { 0, 1, 2 })
  cout << n << " ; ";
```



