  .global main
main:
  call readi32 // call of the function from library
  mov %eax, %edx // copying value from one to another register
  call readi32
  // mov $50, %eax // move contant value (copy to another register)
  add %edx, %eax // sum up values in the second register
  call writei32
  call finish
