---
id: go-servers
aliases:
  - go
  - servers
tags: []
---

# Server Performance

## JS (`Node.js`, `Express.js`)

```mermaid
flowchart LR
    A(Client) -->|Request|B(Node.js Server)
    B -->|Event loop|B
```

- Single-threaded, can process I/O bound operations through regular process switches (`async event loop`)
- It is done with `Promises`: operations are deferred to time I/O is done, so other operations can be taken into account

## Python (`Django`, `Flask`)

_WSGI_: Web Server Gateway Interface - a standard protocol for communication between web servers and web applications

```mermaid
flowchart LR
    A(Client) -->|Request|B(WSGI)
    B -->|Wrapped Request|C(Python Application)
```

To parallel the requests, WSGI spawns a new python application entity for each one.

## Go

```mermaid
flowchart LR
    A(Client) -->|Request|B(Go Server)
    B --> C[Go routine] & D[Go routine] & E[Go routine]
```
