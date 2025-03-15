# C++ Functions

## `Make` utility

For automatization, there is a `make` utility, that provides dependencies for compilation several
files, default syntax:

```Makefile
aim: dependencies
[tab]  command
```

To call one of the aims (commands), we should write `make name_of_command`
To divide dependencies, we should provide them for all files, in case if one changes, only this file
will be recompiled

```Makefile
CC=g++
FLAGS=-std=c++20 -Wall -Wextra -Werror
all: my_prog

my_prog: main.o square.o
    $(CC) $(FLAGS) -o my_prog main.o square.o

main.o: main.cpp square.h // construct object file
    $(CC) $(FLAGS) -c main.cpp

square.o: square.cpp square.h
    $(CC) $(FLAGS) -c square.cpp

clean:
    rm -rf *.0 my_prog
```

## Functions

- It is code fragment, which can be executed by processor and lies in the memory by certain address
- Function can return the value which type in most cases is similar to function type itself
- If function does not return any value, it should be `void` type (such functions called procedures)
- Function can take parameters (or can not take)
- Function can be overloaded

Functions declarations have the following structure:

`prefix_modifications return_type function_name(arguments) suffix_modifications`

```cpp
int square();
int square(double num) noexcept;
virtual int square(int num, isigned int p) noexcept;
```

### Prefix modifications

- `static` indicates that a function that is not a member of the class has an internal relationship
  (will not be used outside its translation unit)
- `virtual` indicated that method can be overwritten by child class
- `constexpr` indicated that function should be executed in compile time if it is possible
- `[[noreturn]]` indicated that function does not return a value. Such attribute help compiler to
  optimize the code
- `inline`, which play role in compiler optimizations
  - tell the compiler that it should try to generate the function in call place
  - compiler can avoid this message
  - body of inline function should be defined in the same translation unit as declaration

### Suffix modifications

- `noexcept` indicates that function will never throw an exception, this help for certain optimizations
- `const` indicates that method will not change the instance of its class, so const instances can
  call such method
- `final` indicates that method will not be overwritten in child class
- `override` indicates that method is overwritten version of base class
- `volatile` for optimizing multi-thread programs

## Call stack

- Put argument into the call stack
- Put the return address onto the stack
- Jump into the calling function
- After function execution jump to the return address
- Clear the call stack

### cdelc (c-declaration)

Before function call the code be inserted called prolog and following steps are executed:

- saving register values using inside the function
- writing to the stack of function arguments

### thiscall

Calls agreement which used by C++ compilers for class methods calls
Differs from **cdecl**-agreement only in that pointer to the object in which method calles (`this`
pointer) is written in `ecx` register

### fastcall

Parameters are sent by registers: if for all parameters and temporary results there are not enough
registers stack is used (in GCC first two parameters are sent with `ecx` and `edx` registers)

### System V AMD64 ABI (Linux, macOS, FreeBSD)

- 6 register for integer-like arguments
- 8 registers for double/float-like arguments
- if there are more arguments, they are sent using stack
- for returning integer-like value `RAX` and `RDX` registers are used (64 + 64 bits)

## Attributes

- Attributes lets programmers add additional restrictions on source code and let compiler new
  opportunities for optimization
- We can use attributes for types, variables, functions, names and code blocks
- **(C++11)** `[[noreturn]]`: indicates that function does not return a value
- **(C++14)** `[[deprecated]]`: indicates that you should avoid this name
- **(C++17)** `[[maybe_unused]]`: suppresses compiler warning
- **(C++20)** `[[nodiscard("reason")]]`: shows warning if return value is not used

## Stronger attributes

- `__attribute__((always_inline))`
- `__forceinline`
- `[[gnu::always_inline]]`

Compiler tries to integrate function regardless of function characteristics
In several cases, compiler can avoid such integration:

- Recursive function does never integrate inside itself
- If inside the function `alloca();` is used
- In any case, there are no guaranties

## Functional object

Class or structure instance that can behave like function: has overloaded `operator()`

```cpp
template <typename T>
class Less {
    const T& x_;
public:
    Less(const T& x): x_(x) {}

    bool operator()(const T& y) const {
        return y < x_;
    }
};

Less lessThen(3);
bool result = lessThen3(5); // false
```

## Passing arguments

- by value
  - in function will be copied of object, it's changing do not respond on the original object
  - copying big objects is expensive operation
- by lvalue-reference
  - there is **no copying**, all the changes will respond on the original object
  - should use, if we want to change parameter object
- by lvalue-const-reference
  - object won't be changed, and copying as well
- by pointer
  - no copying
  - const protects object from changing inside function
  - _optional-conception_

## Function overloading

- Using the same name for operation but with different types called **overloading**
- The search process of accepting function lies into searching for the best accordance formal and
  real arguments for function
- Functions, declared in different fields of view are not overloaded
- Overloaded function - decorated function

### Order for choosing a variant of overloading

1. Exact match of types either possibility of trivial casting
2. Compiler will try to use integer types for float types
3. Compiler will try to compare types using standard manipulations for casting
4. Compiler will search for user casting
5. Compiler will search for variate function (`...`)

#### Variate functions

```cpp
int sum(size_t n, ...) {
    va_list args;
    va_start(args, n);
    int result{};

    while(n--) {
        auto next_element = va_arg(args, int);
        result += next_element;
    }

    va_end(args);
    return result;
}
```

## Functions of the highest order

Function that takes as arguments other functions (callback-functions) or returns other function as result

```cpp
void sort(int* data, size_t size, bool (*compare)(int x, int y));
bool less(int x, int y) {
    return x < y;
}
sort(data, 100, less);
```

## Lambda-functions

`[captures](parameters) specifiers -> return type {body}`

- captures: variable-members of function object
- parameters: parameters for function call
- body: code of function object
- specifiers: elements like `constexpr`, `mutable`, `noexcept` and `[[noreturn]]`
- return type: type that function object returns
