package main

import (
	"fmt"
	"sync"
)

func BufferedRangeGenerator(start, end, buffer int) chan int {
	ch := make(chan int, buffer)

	go func() {
		defer close(ch)

		for i := start; i <= end; i++ {
			ch <- i
		}
	}()

	return ch
}

func WorkerFn(ownId int, source chan int, res chan string, wg *sync.WaitGroup) {
	defer wg.Done()

	for n := range source {
		res <- fmt.Sprintf("I am worker %d: processing value %d", ownId, n)
	}
}

func main() {
	const (
		rangeStart = 1
		rangeEnd   = 8
		poolSize   = 3
	)

	src := BufferedRangeGenerator(rangeStart, rangeEnd, poolSize)

	wg := sync.WaitGroup{}
	res := make(chan string)

	for i := 0; i < poolSize; i++ {
		wg.Add(1)
		go WorkerFn(i, src, res, &wg)
	}

	go func() {
		wg.Wait()
		close(res)
	}()

	for r := range res {
		fmt.Println(r)
	}
}
