---
id: week-3-seminar
aliases: []
tags: []
---

# Protobuf

<!--toc:start-->
- [Protobuf](#protobuf)
  - [Standard implementation](#standard-implementation)
  - [gRPC](#grpc)
    - [`reflection`](#reflection)
<!--toc:end-->

Protobuf is a special protocol for serializing (translation of object structure into sequence of bytes and) data introduced by Google.

It is like JSON, but more efficient and faster.

Protobuf can be used all where serialization is used (server communication, object's state saving)

Cons of JSON:

- JSON is text-based, so it is slower to parse and serialize
- JSON is not strongly typed, so it is harder to validate

## Standard implementation

Protobuf lies in `.proto` files. These files are used to define the structure of the data that you want to serialize.

```proto
syntax = "proto3";

message Person {
  string name = 1;
  int32 id = 2;
  string email = 3;
}
```

Here, the `message` is a unit of information that you want to serialize.
Each field in `message` contains a type, name and a unique number, that show the order of fields.

The only way to work with defined protocol in Go code is to generate code based on such specification files.

## gRPC

gRPC (google Remote Procedure Call - program calls remote procedure in different address space: for web - in a different service; as if it were normal procedure call) a high-performance, open-source universal RPC framework. It is based on Protobuf and HTTP/2.

### `reflection`

`reflection` is a package that provides a way to inspect the structure of a protocol buffer message (without knowledge about the specification itself).

Can be useful for debugging, testing, and other purposes, but should not be in production.
