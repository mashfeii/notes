// NOTE: (A + B) / (C + D)
  .text
  .global main
main:
  push %ebp
  mov %esp, %ebp

  fld a // stack(0) -> a
  fadd b // add b to the stack (b + a)

  fild d // load d into stack (fild -> f int load)
  fadd c  // add c to the stack (c + d)

  // stack: [ st(0) -> c + d      st(1) -> b + a ]

  fdivrp %st(0), %st(1) // st(1) / st(0) -> fdivrPop -> st(1) -> st(0) -> st(0) contains the result
  sub $8, %esp
  fstpl(%esp)

  push $print_format
  call printf

  mov %ebp, %esp
  pop %ebp

  .data
a:
  .float 1.1
b:
  .float 2.2
c:
  .float 3.3
d:
  .int 4

print_format:
  .string "%f\n"
