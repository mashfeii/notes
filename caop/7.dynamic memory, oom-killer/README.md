# Dynamic memory

The main function for memory allocation are `malloc(size_t size)`, `calloc(size_t num, size_t size)`, `free(void* ptr)`
Also, there is `realloc(void *ptr, size_t size)` function, that can be useful for array
implementation, but such function call **bust not** be assigned to the previous pointer

Also, since memory allocation is an expensive operation (it makes request to the OS), `malloc`,
usually, takes more memory on the first call (to store the part of it for future calls without
interaction with OS)
`address brk(address)` is a system call interface for memory allocation, C has its own wrapper for such
interaction: `int brk(address)` and `int sbrk(size_t amount)`

`malloc` contains singly-linked list of memory fragments
`free` function do not remove the pointer, just remove access to allocated memory, since that, the
good code style is:

```cpp
void* ptr = malloc(size_t size);
free(ptr);
ptr = nullptr; // NULL for C
```

[In this example](./malloc_zero.c) represented the work of `oom-killer`, since program start using
all the possible memory on computer
On Linux, there is a special command `cat /proc/proc_id/oom_score` that shows current score for
`oom-killer` (program with the highest score will be killed); `dmesg -T` - command that shows recent
system events

`valgrind` - useful Linux command for memory mistakes validation (`--leak-check=full` - one of
possible flags)
