---
id: general-question
aliases: []
tags: []
---

# General Questions

## Which value will print the `defer` statement in the following code?

```go
func deferPrint() {
    var s = 1
    defer fmt.Println(s)
    s++
}
```

Answer: **1**
Justification: The `defer` statement will print the value of `s` at the time of the `defer` statement, which is 1.

> A deferred function’s arguments are evaluated when the defer statement is evaluated.
