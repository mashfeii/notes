## C++ Classes 
1. A user-defined __compound__ type 
2. A user-defined type that behaves __by the same rules__ as predefined types 
3. A basis for object-oriented software design & development (Encapsulation, Inheritance, Polymorphism)

## Two ways for creating objects: __static__ & __dynamic__
__Object__ `x`:
- Is created __by its declaration__ (in stack).
- Is accessed __by its name__;
- Exists __until the end of the scope__ where it was created (statically determined lifetime)

__Object pointed to by__ `p`:
- Is created by the __explicit creation operator__ (in heap).
- It is __unnamed object__; is accessed via the pointer.
- Exists until the explicit deletion operator is performed (dynamically determined lifetime) - or until the whole program terminates.

```cpp
{
    int x = 7; // Static creating
    int *p = new int(7); // Dynamic creating
    //...
    delete p; // Prefix unary operators
}
```

> [!NOTE] Definition
> __Initialization__ deals with the object being created - whereas...
> __Assignment__ works with the object that was created before.

### How Work With Objects?
1. __How to access objects:__
  - By its name (for statically defined ones)
  - Via a pointer to it (for dynamically created ones)
2. __How to manipulate objects:__
  - Using operators defined for the object's type 
  - Using user-defined operations 

```cpp 
{
    float x = 7.7;
    char *p = new char[10];

    x = x * 0.25; // Access by name 
    p[7] = 's'; // Access by pointer
    *(p + 1) = (char) 0x20; 
}
```

For such assignments we need to create __Copy Constructor::__
```cpp 
class C {
    int a;
    C ( C &c) : a(c.a) {}; // __Constructor is private__
public:
    C() : a(0) {};
    C( int i ) : a(i) {};
};

int main() {
    // For each of these assignments we must have copy constructor
    C c4 = C(1);
    C c5 = C();
    C c6(c3);
    C c7 = c4;
```

## Classes & Fundamental Types 
This class behaves (almost) exactly as other fundamental types; it can be used everywhere together with other types.

```cpp 
class C {
    int m;
public:
    // Constructors
    C(int i) { m = i; }
    C(C &c) { m = c.m; }
    // Assigment operators 
    C &operator=(C &c) { m = c.m; }
    // Arithmetic operators 
    C operator+(C &c) { return m + c.m; }
    // Conversion functions 
    operator bool() { return m != 0; }
};
```

## C/C++: Object Declarations 
__Common form__ (simplified): `S T name initializer;`
- `S`: __Storage class__ specifier 
- `T`: __Type__ specifier 
- `name`: The __name__ of the object introduced
- `initizalizer`: Specifies __the initial value__ of the object

> [!NOTE]- 
>- _S_ & _initializer_ can be omitted;
  in that case, default meaning is assumed
>- _S_ & _T_ can of in an arbitrary order 
>- Syntax allows several pairs "_name_/_initializer_"
>- "_initializer_" may have different syntactic forms

## Uniform initialization 
```cpp 
double x, y, z;
int sum2 (x + y + z); // OK, but data loss(!)
int sum1 { x + y + z }; // Error: mroe careful checks

class C { ... };
C c1();
int x1(); // functions declaration(!)

C c2 {};
int x2 {}; // OK: ojbect declarations
```

## Constant Expressions 
`const int x = `_Any-expression;_
In general, cannot be used in context requiring constant-expressions
`constexpr int y = `_A-constant-expression;_
Informally: constant expression is an expression whose value can be calculated at compile time

### constexpr-functions
- Applies to both member and nonmember functions, and for constructor;
- Declares that the function can be used in constant expressions;

__Requirements on constexpr-functions:__
- It must be non-virtual;
- Its body should contain the single return statement;
- The arguments and return type must be of literal types (i.e., typically scalar types or aggregates of those);
- For constructors, only init-list is allowed.
