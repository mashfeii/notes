---
id: week-2-seminar
aliases:
  - go-academy
tags:
  - go
---

# OpenApi

<!--toc:start-->
- [OpenApi](#openapi)
  - [Main Aspects](#main-aspects)
  - [Usage Examples](#usage-examples)
  - [Specification Structure](#specification-structure)
  - [Data Types](#data-types)
  - [Code Generation Approaches](#code-generation-approaches)
    - [Spec First](#spec-first)
    - [Code First](#code-first)
  - [`oapi-codegen`](#oapi-codegen)
    - [Opportunities for Go](#opportunities-for-go)
  - [`ogen`](#ogen)
    - [Installation](#installation)
    - [Usage](#usage)
<!--toc:end-->

## Main Aspects

Open API is a specification for HTTP API description, it makes developers and users know how to interact with API without need to read the code or documentation. OpenAPI was first introduced with Swagger project and become popular from there.

1. OpenAPI uses `YAML` or `JSON` for description, which can be useful for generating documentation and testing interfaces.
2. OpenAPI lets describe different variable types: strings, numerical, arrays and objects, also as their restrictions.
3. OpenAPI is part of Linux Foundation → open-source, community takes active part in further depelopment and support.

## Usage Examples

Documentation: one can generate interactive documentation pages (e.g. Swagger UI, Redoc)

- http://swagger.io/tools/swagger-ui/
- http://github.com/Redocly/redoc?tab=readme-ov-file
- https://redocly.github.io/redoc/

Testing: instruments, such as Postman, can import OpenAPI specifications
Client-code generating: Swagger Codegen/OpenAPI Generator are used for generating both server and client side templates

## Specification Structure

- `openapi`: OpenAPI version
- `info`: API information
- `servers`: servers where API is available
- `paths`: routes and methods
- `components`: reused components
  - `schemas`: data structures
  - `parameters`: requests parameters
  - `responses`: possible responses
  - `headers`
- `security`: description for authentification (`OAuth 2.0`, `API`/`JWT` tokens)
- `tags`: list of tags for API separation

## Data Types

Data type is formed from mandatory field `type` and optional modificator `format`.

- `string`
  - `date-time`
  - `binary`
  - `uuid`
- `number`
- `integer`
  - `int64`
- `boolean`
- `object`
- `array`
- `null`

## Code Generation Approaches

### Spec First

First, you need to write OpenAPI specification (`yaml` or `json`), then generate server and client code. This approach
is preferable by most of the developers, because it allows to generate code for different languages and frameworks.

### Code First

This approach assumes that you implement handlers first. They are wrapped with OpenAPI annotations, which are used for
generating specification. This approach is less popular, because it is harder to maintain and update.

```go
package handlers

// @Summary Get user by ID
// @Description Get user by ID
// @ID get-user-by-id
// @Accept json
// @Produce json
// @Param id path int true "User ID"
// @Success 200 {object} User
// @Router /users/{id} [get]
func GetUserByID(w http.ResponseWriter, r *http.Request) {
  // ...
}
```

## `oapi-codegen`

One of the tools for automatic code generation based on OpenAPI specification. It supports various languages and frameworks.

### Opportunities for Go

- Client-side code: allows creating client libraries, which automaticaly implement all the methods, described in
  OpenAPI specification. This makes it easier to work with API, since clients can use ready methods without need to write
  them by hand.
- Server-side code: allows creating server handlers, creating project structure suitable for API. Such code may include
  incoming requests validation, responses serialization, errors handling, etc.
- Configurable templates: allows customizing generated code, for example, to add logging, metrics, etc.
- Frameworks integration: allows integrating generated code with popular frameworks, such as:
  - `Chi`
  - `Echo`
  - `Gin`
  - `Gorilla`
  - `Fiber`
  - `net/http`
- Installation: `go install github.com/oapi-codegen/oapi-codegen/v2/cmd/oapi-codegen@latest`
- Usage:

  - CLI: `oapi-codegen -config config.yaml ../oapi/openapi.yaml`
  - Go generate: `//go:generate oapi-codegen -config config.yaml ../oapi/openapi.yaml`
  - (Rarely) Go tools (`tools/tools.go`):

    ```go
    package tools

    import (
        _ "github.com/oapi-codegen/oapi-codegen/v2/cmd/oapi-codegen"
    )

    // go:generate go run github.com/oapi-codegen/oapi-codegen/v2/cmd/oapi-codegen -config config.yaml ../oapi/openapi.yaml
    ```

## `ogen`

- Allows to extend specification with own descriptions (returning errors, extended type formats, etc.)
- Generates `Handler` interface, which should be implemented and used in `Server` (close to `gRPC` approach)

For each method there are structure of incoming parameters and returning values. Generates stub for handlers - `UnimlementedHandler`.

- Support for tracing `opentelemetry`
- Own interface for `Middleware`
- Own data types for `nullable` fields validation

### Installation

`go install -v github.com/ogen-go/ogen/cmd/ogen@latest`

### Usage

`//go:generate ogen -target ../../api/ogen --clean ../../oapi/openapi.yaml`
