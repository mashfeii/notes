.global for_each
for_each:
  push %ebp
  mov %esp, %ebp
  // NOTE: [ old_ebp return int* arr   int size    void* func ]
  //       ^esp, ebp        ^ebp + 8   ^ebp + 12   ^ebp + 16

  mov 8(%ebp), %eax // array
  mov 12(%ebp), %ecx // size
  mov 16(%ebp), %edx // func

cycle:
  // push other argument to save their values
  push %ecx
  push %edx
  // push argument of the function
  push %eax
  // call *%edx // edx contains address, we need to call dereferenced version
  push $func
  jmp *%edx
func:
  // restore values
  pop %eax
  pop %edx
  pop %ecx

  add $4, %eax // move to the next element in array

  loop cycle

  mov %ebp, %esp
  pop %ebp
  ret
