package pubsub

import "sync"

type Broker struct {
	mu                 sync.Mutex
	subscribersByTopic map[string][]chan string
	defaultBufferSize  int
	closed             bool
}

func NewBroker(defaultBufferSize int) *Broker {
	return &Broker{
		subscribersByTopic: make(map[string][]chan string),
		defaultBufferSize:  defaultBufferSize,
	}
}

func (b *Broker) Close() {
	b.mu.Lock()
	defer b.mu.Unlock()

	if b.closed {
		return
	}

	// NOTE: set logic variable
	b.closed = true

	// NOTE: close each channel
	for _, subs := range b.subscribersByTopic {
		for _, sub := range subs {
			close(sub)
		}
	}
}
