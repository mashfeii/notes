---
id: week-12-seminar
aliases:
  - multithreading
  - data-race
  - goroutines
tags:
  - academy
  - go
---

# Multithreading programming

In Go one can call the async functions using keyword `go`
It does not specify the order of execution, which totaly lies on the developer
Also, one can call as many goroutines as needed

## Data Race

Go can detect the data race - when two goroutines try to access the same variable at the same time, in such case one will get the `fatal error: concurrent map writes`
To get the warning explicitly, there is `-race` flag

## Memory management

Runtime memory management stays on 3 main elements:

- **Allocator**: responsible for allocating
- **Garbage collector (GC)**: responsible for collecting unused memory and freeing it** 
- **Scavenger**: returns unused memory to the OS

### Garbage collection

Implemented with tracing garbage collector. It based on 3-color *mark-and-sweep* algorithm, publicated by Dijkstra and Lemport in 1978.

1. **Mark**: mark all reachable objects (e.g.: in heap)
2. **Sweep**: go through all objects in heap, supress the unreachable ones and return them in free-memory pool

To properly mark the objects, we have to pause the runtime on mark stage, so-called **Stop the World (STW)** 

### Algorithms for reducing STW time

3-color algorithm marks the objects in white, gray and black color.

- **White**: potentially garbage-collectable, but not reached yet
- **Gray**: objects on "consideration"
- **Black**: active objects

### GC Settings

- `GOGC=off` - disable garbage collection
- `debug.SetGCPercent()` - set the percent of live heap's memory, which will be used for GC
- `GOMEMLIMIT` - set the maximum memory usage for Go environment
- `debug.SetMemoryLimit()` - the same, but from runtime 

Go does not undertake memory limitation itself

### Memory allocation

In case when the memory is a bottleneck, one can get closer look on strutucre sizes to properly handle the aligning on memory allocation
Also, you can try to avoid manipulating with heap objects (references as return values, etc.)
