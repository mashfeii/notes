  .global main
main:
  call readi32 // read number
  pushl %eax // push to the stack

  call readi32 // same operation
  pushl %eax

  movl (%esp), %eax // move value from top of the stack to eax
  call writei32

  movl 4(%esp), %eax // shift by +4, move to eax
  call writei32

  popl %eax // pop value from stack to $eax register
  call writei32

  popl %eax
  call writei32

  call finish
