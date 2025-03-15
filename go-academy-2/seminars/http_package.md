---
id: week-1-seminar
aliases: []
tags: []
---

# Simple HTTP server

<!--toc:start-->
- [Simple HTTP server](#simple-http-server)
  - [`http.Handler`, `http.HandlerFunc`](#httphandler-httphandlerfunc)
  - [`ListenAndServe`](#listenandserve)
  - [Multiplexing](#multiplexing)
  - [Most Common Life Cycle](#most-common-life-cycle)
  - [Handling Signals with HTTP Server](#handling-signals-with-http-server)
  - [FastHTTP](#fasthttp)
  - [HTTP Client](#http-client)
  - [Transport](#transport)
  - [Request Tracing](#request-tracing)
  - [resty](#resty)
  - [Middleware](#middleware)
    - [Server-Side Middleware](#server-side-middleware)
    - [Client-Side Middleware](#client-side-middleware)
<!--toc:end-->

## `http.Handler`, `http.HandlerFunc`

`Handler` is an interface that is used to handle HTTP requests and generate HTTP response.
`HandlerFunc` transforms a function to a Handler.

```go
type Handler interface {
    ServeHTTP(ResponseWriter, *Request)
}

type HandlerFunc func(ResponseWriter, *Request)

func (f HandlerFunc) ServeHTTP(w ResponseWriter, r *Request) {
    f(w, r)
}
```

## `ListenAndServe`

`ListenAndServe` is a function that starts HTTP server, listens incoming TCP-requests on specified address and port, and calls appropriate handlers (`http.Handler`), which serves incoming requests.

```go
import (
    "fmt"
    "net/http"
)

func SimpleHandler(w http.ResponseWriter, _ *http.Request) {
    w.WriteHeader(http.StatusOK)
    if _, err := w.Write([]byte("Hello, world!")); err != nil {
        panic(fmt.Errorf("could not serve the response: %w", err))
    }
}

func main() {
    http.Handle("/", http.HandlerFunc(SimpleHandler))
    err := http.ListenAndServe(":8080", nil)

    if err != nil {
        fmt.Println("server failed to start or finished with error: ", err)
    } else {
        fmt.Println("server stopped")
    }
}
```

## Multiplexing

```go
import (
	"fmt"
	"net/http"
)

func SimpleHandler(w http.ResponseWriter, _ *http.Request) {
	w.WriteHeader(http.StatusOK)
	if _, err := w.Write([]byte("Hello, world!")); err != nil {
		panic(fmt.Errorf("could not serve the response: %w", err))
	}
}

func InitRouting() *http.ServeMux {
	mux := http.NewServeMux()
	mux.HandleFunc("/", SimpleHandler)
	return mux
}

func InitServer(addr string, handler http.Handler) *http.Server {
  return &http.Server{
    Addr:    addr,
    Handler: handler,
  }
}

func main() {
  const addr = ":8080"
  server := InitServer(addr, InitRouting())

  if err := server.ListenAndServe(); err != nil {
    fmt.Println("server failed to start or finished with error: ", err)
  } else {
    fmt.Println("server stopped")
  }
}
```

## Most Common Life Cycle

The most of the go application are permanently running. We can take control over them by using signals.
Here are the simple example of program that will run until it gets interrupt signal (`Ctrl + C`).

```go
package main

import (
	"fmt"
	"os"
	"os/signal"
	"syscall"
)

func SignalWarden(signals ...os.Signal) chan struct{} {
	result := make(chan struct{})

	go func() {
		signalCh := make(chan os.Signal, 1)
		signal.Notify(signalCh, signals...)

		<-signalCh
		close(result)
	}()

	return result
}

func main() {
	done := SignalWarden(syscall.SIGINT, syscall.SIGTERM)

	fmt.Println("waiting for signal")
	<-done
	fmt.Println("done")
}
```

HTTP Servers on go run in the same way.

## Handling Signals with HTTP Server

```go
package main

import (
	"context"
	"errors"
	"fmt"
	"net/http"
	"os"
	"os/signal"
	"syscall"
)

func NormalHandler(w http.ResponseWriter, r *http.Request) {
  _, _ = w.Write([]byte("Hello from NormalHandler!\n"))
}

func InitRouting() *http.ServeMux {
  mux := http.NewServeMux()
  mux.HandleFunc("/ok/", NormalHandler)
  return mux
}

func InitServer(addr string, handler http.Handler) *http.Server {
  return &http.Server{
    Addr: addr,
    Handler: handler,
  }
}

func SignalWarden(signals ...os.Signal) chan struct{} {
	result := make(chan struct{})

	go func() {
		signalCh := make(chan os.Signal, 1)
		signal.Notify(signalCh, signals...)

		<-signalCh
		close(result)
	}()

	return result
}

func main() {
  const addr = ":8080"
  server := InitServer(addr, InitRouting())

  go func() {
    <-SignalWarden(syscall.SIGINT, syscall.SIGKILL)
    _ = server.Shutdown(context.Background())
  }()

  if err := server.ListenAndServe(); err != nil && !errors.Is(err, http.ErrServerClosed) {
    fmt.Println("server failed to start or finished with error", err)
  } else {
    fmt.Println("application stopped")
  }
}
```

## FastHTTP

Package `github.com/valyala/fasthttp` is a popular library for HTTP server and handlers. Both server and handlers have a little different signature. Library does not support the routing, but this can be done with another 3d party library
such as `github.com/fashttp/router`.

Code built with `fx` and `net/http` can be easily converted to `fasthttp`.

Also, you only need `fasthttp` in case of high performance requirements.

## HTTP Client

```go
package main

import (
	"bytes"
	"fmt"
	"io"
	"net/http"
	"time"
)

func NewClient() *http.Client {
	const timeout = 1 * time.Second

	return &http.Client{
		Timeout: timeout,
	}
}

func BuildRequest() (*http.Request, error) {
	return http.NewRequest("POST", "http://127.0.0.1:8080/echo/", bytes.NewReader([]byte("Hello, world!\n")))
}

func main() {
	client := NewClient()
	req, err := BuildRequest()
	if err != nil {
		fmt.Println("failed to build request", err)

		return
	}

	resp, err := client.Do(req)
	if err != nil {
		fmt.Println("failed to do request", err)

		return
	}
	defer resp.Body.Close()

	fmt.Println("response status:", resp.Status)

	respBody, err := io.ReadAll(resp.Body)
	if err != nil {
		fmt.Println("failed to read reponse body", err)

		return
	}

	fmt.Printf("response body: %s", respBody)
}
```

## Transport

`http.Client` contains field `Transport` with type `RoundTripper`:

```go
type RoundTripper interface {
    RoundTrip(*Request) (*Response, error)
}
```

If transport is not set, then default one is used:

```go
var DefaultTransport RoundTRipper = &Transport{
    Proxy: ProxyFromEnvironment,
    DialContext: defaultTransportDialContext(&net.Dialer{
        Timeout:   30 * time.Second,
        KeepAlive: 30 * time.Second,
    }),
    ForceAttemptHTTP2:     true,
    MaxIdleConns:          100,
    IdleConnTimeout:       90 * time.Second,
    TLSHandshakeTimeout:   10 * time.Second,
    ExpectContinueTimeout: 1 * time.Second,
}
```

Transport defines various parameters, such as tls configuration, general quantity and lifetime for idle connections.

Important note: transport should not be definied for each request or client, it should be reused. Standard `http.Transport` is thread-safe.

## Request Tracing

`httptrace.ClientTrace` is used to handle more information about detailed steps of the request.

```go
func BuildRequest() (*http.Request, error) {
	trace := &httptrace.ClientTrace{
		GetConn: func(hostPort string) {
			slog.Info("GetConn", slog.String("hostPort", hostPort))
		},
		GotConn: func(info httptrace.GotConnInfo) {
			slog.Info(
				"GotConn",
				slog.Bool("reused", info.Reused),
				slog.Bool("wasIdle", info.WasIdle),
			)
		},
		PutIdleConn: func(err error) {
			slog.Info("PutIdleConn")
		},
		DNSStart: func(info httptrace.DNSStartInfo) {
			slog.Info("DNSStart", slog.String("host", info.Host))
		},
		DNSDone: func(info httptrace.DNSDoneInfo) {
			slog.Info("DNSDone")
		},
		ConnectStart: func(network, addr string) {
			slog.Info("ConnectStart",
				slog.String("network", network),
				slog.String("addr", addr))
		},
		ConnectDone: func(network, addr string, err error) {
			slog.Info("ConnectDone")
		},
		WroteHeaderField: func(key string, value []string) {
			slog.Info("WroteHeaderField",
				slog.String("key", key),
				slog.Any("value", value))
		},
		WroteHeaders: func() {
			slog.Info("WroteHeaders")
		},
		WroteRequest: func(info httptrace.WroteRequestInfo) {
			slog.Info("WroteHeaders")
		},
	}

	const bodyString = "Hello!\n"
	req, err := http.NewRequest("GET", "http://127.0.0.1:8080/echo/", strings.NewReader(bodyString))
	if err != nil {
		return nil, err
	}

	return req.WithContext(httptrace.WithClientTrace(
		req.Context(),
		trace,
	)), nil
}
```

## resty

Using standard `http/net` package includes much of boilerplate code to implement server and handlers: creating client, requests, reading response body, validating errors on each of those steps.

[Code example](./code_examples/resty/main.go)

There are much of packages that simplify this process, such as `github.com/go-resty/resty` package.

`resty` supports much of various functions, including encoding and decoding of request body, as well as tracing of that step.

## Middleware

### Server-Side Middleware

There is an opportunity to run code either before or after the handler is executed. For such purposes middleware is used: often it is a function that takes `http.Handler` and returns `http.Handler`. Middleware is some often used code in different handlers that can be taken out and reused.

Let's add a metric for request duration to the handler from the first part:

```go
package main

import (
	"fmt"
	"net/http"
	"time"
)

func SimpleHandler(w http.ResponseWriter, r *http.Request) {
	w.WriteHeader(http.StatusOK)
	_, _ = w.Write([]byte("Hello!"))
}

func TimingMiddleware(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		start := time.Now()
		next.ServeHTTP(w, r)
		fmt.Printf("request took %s\n", time.Since(start))
	})
}

func main() {
	http.Handle("/", TimingMiddleware(http.HandlerFunc(SimpleHandler)))
	err := http.ListenAndServe(":8080", nil)

	if err != nil {
		fmt.Println("server failed to start or finished with error", err)
	} else {
		fmt.Println("server stopped")
	}
}
```

`resty` also supports middleware both for requests and responses:

- http://resty.dev/docs/request-middleware/
- http://resty.dev/docs/response-middleware/

### Client-Side Middleware

Such middleware are implemented in the same way as server-side wrappers, but instead of wrapping the handler you should wrap the transport.
