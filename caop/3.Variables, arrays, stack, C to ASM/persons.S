  .text
  .global main
main:
  call readi32 // reading address
  mov %eax, %ebx // copy to the temporary register

  mov persons(, %ebx, 8), %eax // address of persons + index * 8 (2 items by 2 bytes) -> eax
  call writei32 // eax holds weight of person by given index

  mov persons+4(, %ebx, 8), %eax // shift previous position by 4 bits (go to the height)
  call writei32
  call finish
  .data
persons:
  .int 80 // weight
  .int 180 // height
  .int 70
  .int 160
  .int 30
  .int 130
