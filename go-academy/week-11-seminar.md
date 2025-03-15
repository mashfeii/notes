---
id: seminar_11
aliases: []
tags: []
---

## Groups

`sync.WaitGroup` - synchronization primitive

- `Add(delta int)` - increments counter
- `Done()` - equals to `Add(-1)`
- `Wait()` - move goroutine in `waiting` state until counter becomes 0

Example:

```go
package main

import (
    "fmt"
    "sync"
)

func main() {
    const workerQty = 7

    wg := sync.WaitGroup{}
    for i := 0; i != workerQty; i++ {
        // NOTE: count the new goroutine
        wg.Add(1)
        // NOTE: spawn new user-thread
        go func(id int) {
            defer wg.Done()

            fmt.Printf("hi from goroutine %d\n", id)
        }(i)
    }

    // NOTE: wait until all are done
    wg.Wait()

    fmt.Println("all goroutines finished")
}
```

```go
func YieldNumbers(bufferSize, N int) chan int {
    // NOTE: create output channel
    out := make(chan int, bufferSize)

    // NOTE: worker push N values to the channel
    go func() {
        defer close(out)

        for i := 0; i != N; i++ {
            out <- i
        }
    }()

    return out
}

func ProcessSourceUsingWorkerPool(src chan int, workerFn func(int), workersQty int) {
    // NOTE: create wait group
    wg := sync.WaitGroup{}

    // NOTE: spawn declared number of workers (goroutines)
    for i := 0; i != workersQty; i++ {
        // NOTE: update the counter
        wg.Add(1)
        go func() {
            // NOTE: decrement as done
            defer wg.Done()

            // NOTE: process channel values
            for value := range src {
                workerFn(value)
            }
        }()
    }

    // NOTE: wait until all are done
    wg.Wait()
}

func main() {
    const workersQty = 7

    ProcessSourceUsingWorkerPool(
        // NOTE: creating a channel of values
        YieldNumbers(workersQty, 2*workersQty),
        // NOTE: worker function to process values
        func (value int) {
            fmt.Println("hi from goroutine with id", value)
        },
        // NOTE: number of workers
        workersQty
    )
}
```
