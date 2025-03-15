  .text
get_person_address:
  // address = %eax (index) * 8 + persons start address
  leal persons(, %eax, 8), %eax // computes address with multiplier 8 (2 ints), returns to %eax
  ret

  .data
persons:
  .int 80
  .int 180
  .int 70
  .int 160
  .int 30
  .int 130

  .text
  .global main
main:
  call readi32 // get index

  call get_person_address // compute the address
  movl %eax, %edx // copy value (address) to edx

  movl (%edx), %eax // dereference address into eax
  call writei32

  movl 4(%edx), %eax // dereference address (shifter by 1 int) into eax
  call writei32

  call finish
