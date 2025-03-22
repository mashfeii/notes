---
id: configuration
aliases: []
tags: []
---

# Type Safe Configuration

There are two common types of configuration in a project: file-based and environment-based.

## File-based Configuration

The best approach to handle configuration in a file is to use `.yaml` file.

For Go projects, the best way to parse configuration from a file is `spf13/viper` package.

Also, it is a good practice to embed default configuration via `go:embed file_name` directive.

```go
package main

import (
    "fmt"
    "github.com/spf13/viper"
)

func main() {
    viper.SetConfigName("config")
    viper.AddConfigPath(".")
    viper.SetConfigType("yaml")

    if err := viper.ReadInConfig(); err != nil {
        fmt.Println("Error reading config file, %s", err)
    }

    fmt.Println("Using config file:", viper.ConfigFileUsed())
    fmt.Println("Name:", viper.GetString("name"))
    fmt.Println("Age:", viper.GetInt("age"))
}
```

## Environment-based Configuration

Here, the common library to parse environment variables is `github.com/caarlos0/env/v11`, it can be used without any
files, since it can configure default values for each variable.

```go
type Config struct {
    Name string `yaml:"name" env:"NAME" envDefault:"John"`
    Age  int    `yaml:"age" env:"AGE" envDefault:"30"`
}

func main() {
    conf := &Config{}
    if err := env.Parse(conf); err != nil {
        fmt.Printf("%+v\n", err)
    }
}
```
