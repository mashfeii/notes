---
id: week-13-seminar
aliases: []
tags: []
---

## Publisher-subscribers model

Members of one group publish data. Member of another one subscribe to this data. Members do not exchange data straight forward, but do it through broker.

In case with several subscribers, each one either could get a copy of the message or be subscribed on certain set of data which do not interfere with other subscribers.

### Go implementation

The simplest one is to use channels as synchronization primitive. Also, subscribers can not recieve the data that was sent earlier than they were subscribed.

[More complex example](./seminar13/pub-sub/main.go)

## Semaphores

Semaphores are needed in case you want to limit the number of goroutines working with shared resource.
Mutex is the example of semaphore with limit equals to 1. The simplest way to implement semaphore with limit N based
on buffered channel.

[Example of code](./seminar13/semaphore/main.go)
