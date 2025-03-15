# Linking the library

1. If the library is _tiny_, once can just add the source in the executable files
2. Otherwise, one need to specify `add_library(name files)`
3. And also **link it** to the executable `target_link_libraries(executable_target_link_to linked_library)`

> [!NOTE]
> CMake does not need to also be rebuilt, it understands if something has changed and regenerates
> its cache on make command

## Scripting Basics

CMake accept all the arguments as strings: `project(string string string)` equals
`project(SampleProject VERSION 1.0.0)`
Variables can be set by `set(name value)` function and used after with `${name}` in string
interpolation: `message(STATUS "Hello, ${name}")`

## Functions, scopes

Except the local variables, CMake also has global with function `set_property(SCOPE NAME VALUE)`, which can be got with `cmake_get_property(new_name NAME)`

```cmake
set_property(GLOBAL PROPERTY FOO
            1 
            2 
            3)
cmake_get_property(foo_var FOO)
message(STATUS "FOO value is ${foo_var}")
```
