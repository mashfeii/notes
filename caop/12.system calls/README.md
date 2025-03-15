`atexit()` is a hook function for calling parameter function before exiting the program, but not on
runtime error
`echo $?` shows the last action's exit code
`exit()` can be not only the function, but a system call without wrapper also - `_exit()` (function
contains this function call in the end)

`strace executable_file` can show which system calls were called

For writing in console C uses buffer and calls OS only when buffer is full, but one can clear the
buffer (and call the OS) by himself with function `fflush(stdout)` or `\n` in the end of line
Making a system call is an expensive operation, thus, console out without clearing buffer works in
several times faster than with it
