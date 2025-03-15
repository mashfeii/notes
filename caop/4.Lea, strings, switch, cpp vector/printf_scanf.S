 .global main
main:
  push %ebp
  mov %esp, %ebp

  sub $8, %esp
  lea -4(%ebp), %eax
  push %eax
  lea -8(%ebp), %eax
  push %eax
  // arguments &A, &B 
  push $string_format
  // argument "%d %d"
  call scanf
  // stack at this moment 
  // [ "%d %d", &A, &B, A, B, old_ebp, return, xxx ]
  //   ^ esp           ^ vals ^ ebp                ^ stack bottom

  cmp $2, %eax
  jne fin

  // ebp - 4 = A; ebp - 8 = B 
  mov -8(%ebp), %eax
  add -4(%ebp), %eax // eax = B + A 

  mov -8(%ebp), %edx
  sub -4(%ebp), %edx // edx = A - B 

  push %edx
  push %eax
  push $printf_format
  call printf

fin:
  mov %ebp, %esp
  pop %ebp
  ret

printf_format:
  .string "sum: %d, diff: %d \n"
string_format:
  .string "%d %d"
