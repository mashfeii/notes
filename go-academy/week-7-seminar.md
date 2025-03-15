---
id: week-7-seminar
aliases: []
tags:
  - go
  - academy
  - network
---

# Working with network

Network protocols:

- OSI: 7 layers
- TCP (Transmission Control Protocol)/IP: 4 layers - physical, canal, **transport** (TCP/UDP), **application**

```go
// NOTE: create listener on specific port
listener, err := net.Listen("tcp", ":8080")
if err != nil {
    panic(err)
}
defer listener.Close()

fmt.Println("TCP-Server is running on 8080 port")

for {
    conn, err := listener.Accept()
    if err != nil {
        fmt.Println(err)
        continue
    }

    // NOTE: handle connection within another goroutine
    go handleConnection(conn)
}

func handleConnection(conn net.Conn) {
    defer conn.Close()

    // NOTE: reading data from connection
    message, _ := bufio.NewReader(conn).ReadString('\n')
    fmt.Println("Receive message:", message)
    // NOTE: sending the request to client
    conn.Write([]byte("Hello from server!\n"))
}
```

### Note on concurrency

```go
func main() {
    // push 0xf20f16
    // call _goscheduler
    go someFunction(someParameter)

    // call 0xf20f16
    // this is default jump command
    someFunction(someParameter)
}
```

## UDP (Unified Datagram Protocol)

Alternative for TCP, it is faster, but do not provide guaranty for package delivery
Used in real-time cases: games, video-conferences

```go
func main() {
    addr, err := net.ResolveUDPAddr("udp", ":8080")
    if err != nil {
        panic(err)
    }

    conn, err := net.ListenUDP("udp", addr)
    if err != nil {
        panic(err)
    }
    defer conn.Close()

    fmt.Println("UDP server is running on 8080 port")

    buffer := make([]byte, 1024)
    for {
        n, clientAddr, err := conn.ReadFromUDP(buffer)
        if err != nil {
            fmt.Println(err)
            continue
        }

        fmt.Printf("Received message: %s from %s\n", string(buffer[:n]), clientAddr)

        conn.WriteToUDP([]byte("Hello from UDP-server!\n"))
    }
}
```

> [!NOTE]
> IP packet
> Header: destination port, source port
> Body
> TCP Connection:
> Client → Server SYN: destination port 80, source port 12345
> Server → Client ASK: destination port 12345, source port 80
> Client → Server SYN: destination port 80, source port 12345

## HTTP (HyperText Transfer Protocol)
