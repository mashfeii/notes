  .global main
main:
  xor %edx, %edx // insert in %edx 0 value
  // mv $0, %edx // analogue
beg:
  call readi32
  jc fin // jump (carry flag) - go to the final in case of overflow
  add %eax, %edx // accumulate sum
  jmp beg // repeat, like loop
fin:
  mov %edx, %eax // copy from temporary to output register
  call writei32 // printf the result
  call finish
