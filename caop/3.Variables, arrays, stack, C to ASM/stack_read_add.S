read_and_add:
  push %ebp // ebp pushed to the initial position of the stack
  mov %esp, %ebp // esp moved up by one position (4 bites)
  
  sub $8, %esp // esp moved up by 8 bites (esp looks at the top of available space, ebp - bottom)

  call readi32
  mov %eax, -4(%ebp) // place value at the stack one position up from ebp - lower bound

  call readi32
  mov %eax, -8(%ebp) // place the second value (two position up from ebp)

  xor %eax, %eax // nullifie eax
  add -8(%ebp), %eax // sum up values from stack into eax
  add -4(%ebp), %eax

  mov %ebp, %esp // return ebp to the initial position (call agreement)
  pop %ebp
  ret

  // structure corresponds to C/C++ structures
  .global main
main:
  call read_and_add
  call writei32
  call finish
