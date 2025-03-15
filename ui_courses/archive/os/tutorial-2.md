When an interrupt or a system call transfers control to the operating system, a kernel stack are separate from the stack of the interrupted process is generally used. Why?

The separate stack area is used for the interrupted processes. The causes for using the distinct stack for kernel are as
given below:

- By using distinct stack, the data is not overwritten on the kernel
- By doing so, the operating system will not crash
- To protect the information of processes from malicious users
- The separate memory space can be used to make system calls

### Task

Multiprogrammed system with degree of 6, where each process spends 40% of its time waiting for I/O, here the CPU utilization:
$1 - (P)^{n} = 1 - (0.4)^{6} = 1 - 0.004096 = 0.99590$
