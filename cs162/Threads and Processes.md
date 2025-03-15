# 2024-03-20 22:21

## What Threads Are

- Definition from before: *A single unique execution context*
  Describes its representation
- It provides the abstraction of: *A single execution sequence that represents a
  separately schedulable task*
- Threads are a mechanism for *concurrency* (overlapping execution)
  However, the can also run in *parallel* (simultaneous execution)
- Protection is an orthogonal concept
  A protection domain can contain one thread or many

### Motivation for Threads

- Operating systems must handle multiple things at once (MTAO)
  Process, interrupts, background system maintenance
- Networked servers must handle MTAO
  Multiple connections handled simultaneously
- Parallel programs must handle MTAO
  To achieve better performance
- Programs with user interface often must handle MTAO
  To achieve user responsiveness while doing computation
- Network and disk bound programs must handle MTAO
  To hide network/disk latency
  Sequence step in access or computation

### Threads Allow Handling MTAO

- Threads are a unit of *concurrency* provided by the OS
- Each thread can represent one thing or one task

## Multiprocessing vs. Multiprogramming

- Some Definitions:
  Multiprocessing: Multiple CPUs (cores)
  Multiprogramming: Multiple jobs/processes
  Multithreading: Multiple threads/processes
- What does it mean to run two threads concurrently?
  Scheduler is free to run threads in any order and interleaving
  Thread may run to completion or time-slice in big chunks or small chinks

### Concurrency is not Parallelism

- Concurrency is about handling multiple things at once (MTAO)
- Parallelism is about doing multiple things *simultaneously*
- Each thread handles or manages a separate thing or task
- But those tasks are not necessarily executing simultaneously

### Threads Mask I/O Latency

- A thread is in one of the following three states:
  running - running
  eligible to run, but not currently running - ready
  ineligible to run - blocked
- If a thread is waiting for an I/O to finish, the OS marks it as
  **blocked**
- One the I/O finally finishes, the OS marks it as **ready**

## Multithreaded Programs

- You know how to compile a C program and run the executable
  This creates a process that is executing that program
- Initially, this new process has *one thread* in its own address space
  With code, globals, etc. as specified in the executable
