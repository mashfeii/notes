# Operating Systems are at the Heart of all

Make the incredible advance in the underlying technology available to a rapidly evolving
body of applications

- Provide __consistent abstractions__ to applications, even on different hardware
- Manage __sharing of rources__ among multiple applications

The key building blocks:

- Processes
- Threads, Concurrency, Scheduling, Coordination
- Address Spaces
- Protection, Isolation, SHaring, Security
- Communication, Protocols
- Persistent storage, transactions, consistency, resilience
- Interfaces to all devices

## What does an Operating System _do_?

Most likely:

- Memory Management
- I/O Management
- CPU Scheduling
- Communications?
- Multitasking/multiprogramming?

What about?

- File System?
- Multimedia Support?
- User Interface?
- Internet Brower?

## Definition of an Operating System

- No universally accepted definition
- "Everything a vendor ships when you order an operating system" is good approximation
- "The one program running at all times on the computer" is the __kernel__

> [!NOTE]- One of possible definitions
> Special layer of software that provides application software access to hardware
> resources

## Wht makes something a __system__?

- Multiple interrelated parts
  - Each potentially interacts with the others
- Robustness requires an __engineering mindset__
  - Melticulous error handling, defending against malicious careless users
  - Treating the computer as a concrete machine, with all of its limitations and possible
    failutre cases

## What is an Operating System?

- Illusionist
  - Provide clead, ease-to-use abstractions of physical resources: "infinite memory,
  dedicated machine", "higher level objects: files, users, messages", "masking
  limitations, virtualization"
- Referee
  - Manage protection, isolation, and sharing of resources: resources allocation and
  communication

> A programm begin a process when the binary has been loaded into the memory and into the
> proper OS structure.

## OS Basics: Protection

- OS _osilates_ processed from each other
- OS _osilates_ itself from other processes
- Even though they are actually running on the same hardware

## Societal Scale Information Systems

- The world is a larget distributed system
  Microprocesors in everything
  Vast infrastructure behind them

## Technology Trens: Moore's Law

Gordon Moore (co-founder of Intel) predicted in 1965 that hte transistor denity of
semiconductor chips would double roughly every 18 months. (2x transistors/Chip every 1.5
years)
