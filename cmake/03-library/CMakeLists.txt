# This is a comment

cmake_minimum_required(VERSION 3.14)
project(SampleProject VERSION 1.0.0)

message(STATUS "I am the message")
add_library(
  say-hello STATIC
  hello.hpp
  hello.cpp
)

set(my_value 1)
while(my_value LESS 50)
    message(STATUS "Value: ${my_value}")
    math(EXPR my_value "${my_value} + 1")
endwhile()

add_executable(cmake-good main.cpp)
target_link_libraries(cmake-good PRIVATE say-hello)
