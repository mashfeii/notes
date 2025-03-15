---
id: week-13-seminar
aliases:
  - reflect
  - reflection
tags:
  - go
  - academy
---

# Reflection

<!--toc:start-->
- [Reflection](#reflection)
  - [Code Generation](#code-generation)
    - [Enums in Go](#enums-in-go)
<!--toc:end-->

Reflection often used in marshaling, working with databases - case, when you need to know type of data you are working with, but, probably, do not know it before validating

```go
func main() {
    a := struct {
        A int
        B string
    }{
        A: 1,
        B: "2",
    }

    // INFO: here, Marshal do not know anything about types,
    //       so it must to validate type of each field
    json, _ := json.Marshal(a)
    fmt.Println(string(json))
}
```

Since type interface contains type and value, we can take in out of variable/structure using `reflect`

```go
func main() {
    var interface{} x = 42

    t := reflect.TypeOf(x)
    v := reflect.ValueOf(x)

    fmt.Println(t, v)
}
```

In case to marshal structures, we can append custom field names with `json` tag

```go
func main() {
    a := struct {
        A int `json:"some_integer_field"`
        B string
    }{
        A: 1,
        B : "2",
    }

    json, _ := json.Marshal(a)
    fmt.Println(string(json))
}
```

## Code Generation

It is often a good practice to generate code for different purpose
In go it can be proceeded with `//go:generate cli_command`:

- `stringer` - generate string representation of type
- `mockery` - generate mocks for interfaces
- `gotests` - generate tests for functions

Also, you should not create an API, but generate it:

- `swagger` - generate documentation for API (OpenApi)
- `protobuf` - gRPC (google remote procedure call)

### Enums in Go

The number of enums are often predefined - they cannot be changed on runtime
But, since Go do not support enums, fields can be produced as new type variables
Initially you create a custom type definition `type MyType string` (`string` are not so efficient as integers, but more often used)
Followed by definition of several constants

```go
type Role string

const (
    RoleAdmin Role = "Admin"
    RoleUser Role = "User"
    RoleGuest Role = "Guest"
)

func NewRole(role string) (Role, error) {
    switch role {
    case "Admin":
        return RoleAdmin, nil
    }
    case "User":
        return RoleUser, nil
    default:
        return RoleGuest, nil
    }
}

func main() {
    role := Role("RoleUnauthorized") // NOTE: new enum
}
```
