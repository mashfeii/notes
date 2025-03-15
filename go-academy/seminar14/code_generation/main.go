package main

import (
	"fmt"
)

type Role string

const (
	RoleAdmin Role = "Admin"
	RoleUser  Role = "User"
	RoleGuest Role = "Guest"
)

func main() {
	role := Role("Unauthorized")
	fmt.Println(GetRole(role))
}

//go:generate mockery --all --with-expecter
type RoleRepo interface {
	GetRole(r Role) string
}

func GetRole(r Role) string {
	panic("unimplemented")
}
