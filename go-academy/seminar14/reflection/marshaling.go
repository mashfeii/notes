package main

import (
	"encoding/json"
	"fmt"
	"reflect"
)

type User struct {
	Name string `json:"name"`
	Age  int    `json:"age"`
}

func PrintStructTags(s interface{}) {
	t := reflect.TypeOf(s)
	if t.Kind() == reflect.Struct {
		for i := 0; i < t.NumField(); i++ {
			field := t.Field(i)
			fmt.Printf("Field: %s\tTag: %s\n", field.Name, field.Tag.Get("json"))
		}
	}
}

func main() {
	a := struct {
		A int `json:"some_integer_field"`
		B string
	}{
		A: 1,
		B: "2",
	}

	var b User

	PrintStructTags(b)

	json, _ := json.Marshal(a)
	fmt.Println(string(json))
}
