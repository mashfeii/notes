# 2024-06-04 20:16

## Function pointers

Every function has its own address in memory, so one can use the pointer to it to call this
function. In assembly such functionality works with help of `labels`, one can jump to it or call.

Also, references and pointers are almost the same in assembly code, only compiler knows the
difference and can implement its optimizations according to specified type.

## Variadic arguments

Feature, that looks the same as template fold expression `template <typename... Args>`.
This thing is used in parameter, when function can somehow handle the certain number of arguments.

```cpp
int get_sum(int number_of_elements, ...);
```
