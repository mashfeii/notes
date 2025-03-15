package main

import (
	"fmt"
	"os"
	"sync"
	"time"
)

func hello() {
	fmt.Println("Hello, world!")
}

func goodbye() {
	fmt.Println("Goodbye, world!")
}

func Example() {
	go hello()
	go goodbye()

	time.Sleep(200 * time.Millisecond)
	fmt.Println("Function done")
}

func SimpleDataRace() {
	c := make(chan bool)
	m := make(map[string]string)

	go func() {
		m["1"] = "a"
		c <- true
	}()

	m["1"] = "b"
	<-c

	for k, v := range m {
		fmt.Println(k, v)
	}
}

func ExampleDataRaceLoopCounter() {
	group := sync.WaitGroup{}
	group.Add(5)

	for i := 0; i < 5; i++ {
		go func() {
			fmt.Println(i)
			group.Done()
		}()
	}

	group.Wait()
}

func ExampleDataRaceSharedVariable(data []byte) chan error {
	res := make(chan error, 2)
	f1, err := os.Create("temp1")
	if err != nil {
		res <- err
	} else {
		go func() {
			_, err = f1.Write(data)
			res <- err
			f1.Close()
		}()
	}

	f2, err := os.Create("temp2")
	if err != nil {
		res <- err
	} else {
		go func() {
			_, err = f2.Write(data)
			res <- err
			f2.Close()
		}()
	}

	return res
}

func ExampleDataRaceChannels() {
	c := make(chan struct{})

	go func() {
		c <- struct{}{}
	}()
	close(c)
}

func ExampleDataRaceSlices() {
	s := make([]int, 0, 1)

	go func() {
		s1 := append(s, 1)
		fmt.Println(s1)
	}()

	go func() {
		s2 := append(s, 1)
		fmt.Println(s2)
	}()

	time.Sleep(1 * time.Second)
}

type Customer struct {
	mutex sync.RWMutex
	id    string
	age   int
}

func (c *Customer) UpdateAge(age int) error {
	c.mutex.Lock() // NOTE: here we locked the mutex
	defer c.mutex.Unlock()

	if age < 0 {
		// BUG: if error occurs, String() method tries to lock the mutex again
		return fmt.Errorf("age must be positive for the customer: %v", c)
	}

	c.age = age
	return nil
}

func (c *Customer) String() string {
	c.mutex.RLock()
	defer c.mutex.RUnlock()
	return fmt.Sprintf("id: %s, age: %d", c.id, c.age)
}

func ExampleDeadlockRWMutex() {
	c := &Customer{id: "123", age: 30}
	err := c.UpdateAge(-1)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println(c)
}

func ExampleDeadlockChannel() {
	ch := make(chan int)
	// BUG: no reader for this channel
	<-ch
	ch <- 1
}

// WARN: variable in heap, since it is a global pointer
var sink *int32

func main() {
	// Example()
	// for i := 0; i < 1e4; i++ {
	// 	SimpleDataRace()
	// }
	// ExampleDataRaceLoopCounter()
	// ExampleDataRaceSharedVariable([]byte("hello"))
	// ExampleDataRaceChannels()
	// ExampleDataRaceSlices()
	// ExampleDeadlockRWMutex()
	ExampleDeadlockChannel()

	id := new(int32)
	*id = 4096
}
