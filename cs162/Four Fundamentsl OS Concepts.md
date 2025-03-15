# Four Fundamental OS Concepts

- Third-party device drivers are one of the most unreliable aspects of OS
  Poorly written by non-stake-holders
- Holes in security model or bugs in OS lead to instability and privacy breaches
- Version skew on Libraries can lead to problems with application execution
- Data breaches, DDoS attacks, timing channels
  Heart bleed

## OS Abstracts Underlying Hardware to help Tame Complexity

Application → *Abstract Machine Interface* → Operating System → *Physical
Machine Interface* → Hardware

- Processor → Thread
- Memory → Address Space
- Disks, SSDs, ... → Files
- Networks → Sockets
- Machines → Processes
- OS as an *Illusionist*:
  Remove software/hardware quirks (*fight complexity*)
  Optimize for convenience, utilization, reliability (\_help the programmer)
- For any OS area (e.g. file systems, virtual memory, networking, scheduling):
  What hardware interface to handle?
  What's software interface to provide?

## First OS Concept: Thread of Control

- **Thread**: single unique execution context
  Program Counter, Registers, Execution Flags, Stack, Memory State
- A thread is *executing* on a processor (core) when it is *resident* in the
  processor registers
- Resident means: registers hold the root state (context) of the thread:
  - Including program counter (PC) register and currently executing instruction
    PC points at next instruction *in memory*
    Instructions stored in memory
  - Including intermediate values for ongoing computations
    Can include actual values or pointers to values *in memory*
  - Stack pointer holds the address of the top of stack (which is *in memory*)
  - The rest is "in memory"
- A thread is *suspended* (not executing) when its state is not loaded (resident)
  into the processor state pointing at one other thread
  - Program counter register *is not* pointing at next instruction from this
    thread
  - Often: a copy of the last value for each register stored in memory

Assume a single processor (core). How do we provide the illusion of multiple
processors?
Multiple in time!
Threads are *virtual cores*
Content of virtual core (thread):

- Program counter, stack pointer
- Registers
  Where is "it" (the thread)?
- On the real (physical) core
- Saved in chunk of memory - called *Thread Control Block (TCB)*

## Second OS Concept: Address Space

- Address space → the set of accessible addressed + state associated with them:
  - For 32-bit processor: $2^{32} = 4\\ \\text{billion}$ addresses
  - For 64-bit processor: $2^{64} = 18\\ \\text{quadrillion}$ addresses
- What happens when you read or write to an address?
  - Perhaps acts like regular memory
  - Perhaps ignores writes
  - Perhaps causes I/O operation
  - Perhaps causes exception (fault)
  - Communicates with another program

### Simple Multiplexing has no Protection

- Operating System must protect itself from user programs
  - Reliability: compromising the operating system generally causes it to crash
  - Security: limit the scope of what threads can do
  - Privacy: limit each thread to the data it is permitted to access
  - Fairness: each thread should be limited to its appropriate share of system
    resources (CPU time, memory, I/O, etc.)
- OS must protect User programs from one another
  - Prevent threads owned by one user from impacting threads owned by another
    user
  - Example: prevent one user from stealing secret information from another user

### Simple Protection: Base and Bound (B&B)

The idea consist in saving two memory addresses: one for start of the thread,
another for its end and allow program works exactly in this address segment

- Still protects OS and isolates program
- Requires relocating loader
- No addition on address path

### Another idea: Address Space Translation

- Program operates in an address space that is distinct from the physical memory
  space of the machine

Processor → "virtual address" → translator → "physical address" → memory

### Paged Virtual Address Space

- What if we break the entire virtual address space into equal size chunks
  (i.e., pages) have a base for each?

- All pages same size, so easy to place each page in memory

- Hardware translates address using a **page table**

  - Each page has a separate base
  - The "bound" is the page size
  - Special hardware register stores pointer to page table
  - Treat memory as page size frames and put any page into any frame

- Instructions operate on virtual addresses

  - Instruction address, load/store data address

- Translated to a physical address through a Page Table by the hardware

- Any Page of address space can be in any (page sized) frame in memory

  - Or not-present

## Third OS Concept: Process

> \[!NOTE\]- Definition
> Execution environment with Restricted Rights
> (Protected) Address Space with One or More Threads
> Owns memory (address space)
> Owns file descriptors, file system context
> Encapsulate one or more threads sharing process resources

- Application program executes as a process
  Complex applications can for/exec child processes

- Why processes?
  Protected from each other
  OS Protected from them
  Processes provides memory protection

- Fundamental tradeoff between protection and efficiency
  Communication easier *within* a process
  Communication harder *between* processes

- Threads encapsulate **concurrency**:
  "Active" component

- Address spaces encapsulate **protection**:
  "Passive" component
  Keeps buggy program from crashing the system

- Why have multiple threads per address space?
  Parallelism: take advantage of actual hardware parallelism
  Concurrency: ease of handling I/O and other simultaneous events

### Protection and Isolation

- Why do we need processes?
  Reliability: bugs can only overwrite memory of process they are in
  Security and privacy: malicious or compromised process can't read or write
  other process' data
  Fairness: enforce shared of disk, CPU
- Mechanisms:
  Address translation: address space only contains its own data
  Why can't a process change the page table pointer?
  Or use I/O instructions to bypass the system?
  Hardware must support **privilege levels**

## Fourth OS Concept: Dual Mode Operation

- Hardware provides at least two modes:
  **Kernel Mode** (or "supervisor" mode)
  **User mode**
- Certain operations are prohibited when running in user mode
  Changing the page table pointer, disabling interrupts, interacting directly
  w/hardware, writing to kernel memory
- Carefully controlled transitions between user mode and kernel mode
  System calls, interrupts, exceptions

### Additional Layers of Protection for Modern Systems

- Additional layers of protection through virtual machines or containers
  Run a complete operating system in a virtual machine
  Package all the libraries associated with an app into a container for
  execution
- More on these ideas later

### 3 types of User ⇒ Kernel Mode Transfer

- Syscall
  Process requests a system service, e.g., exit
  Like a function call, but "outside" the process
  Does not have the address of the system function to call
  Like a Remote Procedure Call (RPC)
  Marshall the syscall id and args in registers and exec syscall
- Interrupt
  External asynchronous event triggers context switch
  e.g., Timer, I/O device
  Independent of user process
- Trap or Exception
  Internal synchronous event in process triggers context switch
  e.g., Protection violation (segmentation fault), Divide by zero

### Running Many Programs

- We have the basic mechanism to
  Switch between user processes and the kernel
  The kernel can witch among user processes
  Protect OS from user processes and processes from each other
- How do we decide which user process to run?
- How do we represent user processes in the OS?

## Conclusion: Four Fundamental OS Concepts

- **Thread: Execution Context**
  Fully describes program state
  Program Counter, Registers, Execution Flags, Stack
- **Address space** (with or w/o **translation**)
  Set of memory addressed accessible to program (for read or write)
  May be distinct from memory space of the physical machine (in which case
  programs operate in a virtual address space)
- **Process: an instance of a running program**
  Protected Address Space + One or more Threads
- **Dual mode operation / Protection**
  Only the "system" has the ability to access certain resources
  Combined with translation, isolates programs from each other and the OS from programs
