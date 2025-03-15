---
id: week-15-seminar
aliases: []
tags: []
---

# Go Compiling

1. `go build` - compiles source code into executable binary
   `go build -o <name> <path>` - the single parameter for name of the output file
   if command is executed from the root directory, the output file will be in the same directory as the source code
2. `go install <path>` - compiles source code from path into `$GOPATH/bin`
3. `go run <path>` - compiles and runs source code
   - `-trimpaths` - remove the path to the source code from the stack trace
   - `-ldflags` - add linker flags
     - `-ldflags "-s -w"` - removes debug information from the binary
4. `go test` - runs tests
   - `./...` - run all tests
   - `go tool cover -func=coverage.out` - print coverage report
   - `go tool cover -html=coverage.out -o coverage.html` - generate HTML report

## Note on CI/CD

To properly achieve product quality (and stay on master branch) code must be properly validated through build and tests. The most popular CI/CD tools are GitHub Actions/GitLab CI as inner systems as well as Jenkins, TeamCity as external systems.

## Cross-Compilation

To properly handle bulid process one may set environment variables, such as:

- `GOOS`: `linux`, `darwin`, `windows`, `freebsd`, etc.
- `GOARCH`: `amd64`, `386`, `arm`, etc.

To handle cross-compilation one can use such tools as [gox](https://github.com/mitchellh/gox).

## Makefile

To use makefile one can use [make](https://www.gnu.org/software/make/manual/make.html).
`.PHONY: <target>` - define a target that is not a file
