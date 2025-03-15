package main

type Semaphore chan struct{}

func NewSemaphore(limit int) Semaphore {
	return make(Semaphore, limit)
}

func (s Semaphore) Acquire() {
  s <- struct{}{}
}

func (s Semaphore) Release() {
  <-s
}

func main() {
  sema := NewSemaphore(3)
  for i := 0; i < 10; i++ {
    go func(semaphore Semaphore) {
      sema.Acquire()
      defer sema.Release()
    }(sema)
  }
}
