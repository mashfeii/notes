---
id: week-9-seminar
aliases: []
tags: []
---

# Testing

The main goal of testing is to make sure that your code works as intended.
Files with tests must be named `*_test.go`, such files wouldn't be compiled with `build` command.

Example if provided [here](seminar9/badtestcode/main.go) (incorrect test file do not ruin running the code)

Each test function starts with `Test` with single parameter `t *testing.T` which is a test object.

## Package naming

There are to types of testing:

- [`blackbox`](seminar9/blackbox): testing is a separate package with `_test` suffix
- [`whitebox`](seminar9/whitebox): testing is a part of the package

The first one is more common, since in working program functions calling such package will not know about underlying implementation details.

## Test lifecycle

Tests are run with `go test` command, one can pass package or list of packages. Command will find test files itself and run all tests in them.
Task for each function is to run piece of code and check that it works as intended with given parameters.
To throw error, one can use `t.Fatal`/`t.Fatalf` or `t.Error`/`t.Errorf` functions. `t.Fatal` will stop the execution, while `t.Error` just mark the test as failed.
