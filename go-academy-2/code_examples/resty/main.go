package main

import (
	"fmt"

	"github.com/go-resty/resty/v2"
)

func main() {
	client := resty.New()
	resp, err := client.R().
		SetBody(map[string]interface{}{
			"name": "Mashfeii",
		}).
		Post("http://127.0.0.1:8080/echo/")
	if err != nil {
		fmt.Println("failed to make a request", err)

		return
	}

	fmt.Println("response status code:", resp.StatusCode())
	fmt.Println("response body:", resp.String())
}
