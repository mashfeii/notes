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
