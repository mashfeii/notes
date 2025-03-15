.global my_sum_up
my_sum_up:
  push %ebp
  mov %esp, %ebp 
  // NOTE: [ %old_ebp   return   counter   ...   ... ]
  //       ^ebp, esp             ^ebp + 8  ^ebp + 8 + x * 4

  mov 8(%ebp), %ecx // ecx - counter, to work with `loop`
  lea 8(%ebp), %edx // first argument address 8 + &ebp

  xor %eax, %eax // nullify result register

cycle:
  add $4, %edx // move to the next argument
  add (%edx), %eax // accumulate

  loop cycle // repeat int_counter times

  mov %ebp, %esp
  pop %ebp
  ret
