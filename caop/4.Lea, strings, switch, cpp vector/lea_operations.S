  .global main
main:
  mov $5, %ecx
  mov $6, %edx

  lea 2(%edx), %eax // eax = 2 + 6
  call writei32

  lea -3(%edx), %eax // eax = -3 + 6
  call writei32

  lea (%ecx, %edx), %eax // eax = 5 + 6
  call writei32

  lea 4(%ecx, %edx), %eax // 4 + 5 + 6
  call writei32

  lea 4(, %edx), %eax // 4 + 6
  call writei32

  lea 4(%ecx, %edx, 2), %eax // 4 + 5 + 6 * 2
  call writei32

  // lea (, %edx, 3), %eax // incorrect multiplier
  // call writei32

  call finish
