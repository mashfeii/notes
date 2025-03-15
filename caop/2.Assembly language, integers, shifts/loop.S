  .global main
main:
  call readi32
  mov %eax, %ecx
print_num:
  mov %ecx, %eax
  call writei32
  dec %ecx
  jnz print_num
  // loop print_num
  call finish
