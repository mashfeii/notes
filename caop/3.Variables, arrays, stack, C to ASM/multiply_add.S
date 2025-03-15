  .global multiply_add
multiply_add:
  push %ebp
  movl %esp, %ebp

  pushl %esi

  movl 8(%ebp), %esi
  movl 12(%ebp), %eax
  // Arithmetic left shift - multiply by 2
  sal $1, %esi
  // %eax = 2 * %esi (a) + %eax (b)
  addl %esi, %eax
  // Return both registers to initial positions (values)
  popl %esi
  popl %ebp

  ret
