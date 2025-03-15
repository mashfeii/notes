## Special Functions by Default
> [!NOTE]- __The important C++ rule:__
> Object of any type should be subject for __creation__, __copying__, and __deletion__ - by default, even if no such operations are provided by programmer.

```cpp
class C {
    int m;
    C() {} //default constructor
    C(C &c) {} // copy constructor
    C(C &&c) {} // to move objects
    ~C() {} // destructor
    C &operator=(C &c) {} // assigning new values
}
```

__The problem with members of the same name__:

```cpp
class Base {
    int m1, m2;
}; 
class Derived : Base {
    float m1;
};
Derived d;
d.m1 = Expression // "m1" from Derived class 
d.Base::m1 = Expression // explicit qualification 
```

## Abstract classes

The class is abstract if it has at least one pure virtual function

```cpp
class Shape {
    // Data common to all shapes 
    // Behavior common to all shapes 
    virtual void Move() = 0;
    virtual void Rotate() = 0;
    virtual void Draw() = 0;
};
```

> [!WARNING]
> We can not create instance of abstract class `Shape* new_shape != new Shape()`

# Functional Programming

Two cornerstones of functional approach:

- Immutable objects: the operations of a program should __map__ input values to output values rather than __change__ data in place
- Functions as "first-class citizens"

> [!IMPORTANT]- The common philosophy in functional programming
> The program functionality is implemented as a (great) number of functions ("building blocks"), each of which performs relatively simple action on its arguments returning the result (without side effect).

Three basic ways for programming functions (C++)... and one more:

- Define a function as an instance member.
- Define function as a class member (~static)
- Define a standalone function.
- Define a function as an object!

## Lambda functions

- If a type has the call operator __operator()__ then the type is called __functional type__.
- If an object is of a functional type it is called __functional object__.

```cpp
auto f = [](int x) { return x + 1; }
f(5);
[](int x){ return x - 1; }(7) // Legal call 
```

`[]` stays for __lambda capture__: we can specify what we want to have in closure

- `[a, &b]`: `a` gets captured by value, `b` by reference
- `[&]`: the whole context by reference
- `[=]`: the whole context by value
- `[=, &a]`: the whole context by value, `a` by reference
- `[this]`: `this` pointer gets captured by value
