---
id: week-6-seminar
aliases: []
tags:
  - go
  - academy
---

# Formatting

## `fmt` package

- If the name of function starts with `F`, it works not with standard input/output, but explicitly with `io.Writer`
  interface: `Println` and `Fprintln`
- Function name starts with `S`: function works with string (`Printf` → `Sprintf`)

## Output in stdout

These interfaces are used for understanding the format of output

```go
type Stringer interface {
    String() string
}
type GoStringer interface {
    GoString() string
}
```

### Print

1. All values are written as is in single line.
2. Function returns the number of written bytes (not arguments) and error if it was occurred.
3. On write used standard formatting for base and complex types
4. Function handle panic in case if there are any.

### Formatting string

- `%v` - value in default format
- `%+v` - (for structures) add fields names
- `%#v` - if type uses `GoStringer` interface, `GoString` is called
- `%d, %x, %b, %o` - decimal, hex, binary, octal
- `%s, %q` - string, quoted string
- `%t` - boolean
- `%f, %e` - float, exponential
- `%T` - type
- `%p` - pointer
- `%%` - literal `%`
