## Encoding order

There are two ways of representing binary code: Big-endian and Little-endian by the first number
order of the number whenever it is the largest one or smallest
For the following example, it is the choice "is '1' goes first or the last?"

```cpp
uint16_t x = 0x0001;
```

## Return Value Optimization (RVO)

Let compiler construct returning object in calling point
Here is good example:

```cpp
Server makeServer(uint16_t port) {
    Server.server(port);
    server.setup(...);
    return server;
}
Server s = makeServer(8080);
```

We should avoid the following constructions:

```cpp
Server&& makeServer(uint16_t port) {
    Server.server(port);
    server.setup(...);
    return std::move(server);
}
```

## Copy elision

Compiler optimization that avoid redundant call of copy constructor

```cpp
struct A {
    explicit A(int) {}
    A(const A&) {}
};
A a = A(5); // copy constructor would not be called
```

## Structured bindings

[Nice articles about C++17 standard](https://habr.com/ru/articles/343622/)

```cpp
std::tuple<std::string, uint8_t> CreatePerson() {
    return std::make_tuple("Say my name", 52);
}
{
    auto items = CreatePerson();
    std::string name = std::get<0>(items);
    uint8_t age = std::get<1>(items);
}
{
    // Since C++17 - structured binding
    auto [name, age] = CreatePerson();
}
```

##
