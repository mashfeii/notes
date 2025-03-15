.global compute_hypotenuse
compute_hypotenuse:
  push %ebp
  mov %esp, %ebp

  push %ebx
  // [ ebx old_ebp return triangles* int_size xxx]
  //  ^esp ^ebp           ^ebp + 8  ^ebp + 12
  // vector pointer
  mov 8(%ebp), %edx
  // vector size
  mov 12(%ebp), %ecx
compute:
  // dereference current struct (leg1)
  mov (%edx), %eax
  imull %eax, %eax // leg1 ^ 2

  // derefence second element in struct (leg2)
  mov 4(%edx), %ebx
  imull %ebx, %ebx // leg2 ^ 2

  // leg1**2 + leg2**2 
  add %ebx, %eax

  movl %eax, 8(%edx) // struct.hypot = eax
  add $12, %edx // move to the next element
  loop compute

  pop %ebx
  mov %ebp, %esp
  pop %ebp

  ret
