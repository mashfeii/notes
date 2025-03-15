package main

import (
	"testing"

	"github.com/vektra/mockery/mockery/fixtures/mocks"
)

func TestGetRole(t *testing.T) {
	repo := mocks.NewRoleRepo(t)

	repo.EXPECT().GetRole(RoleAdmin).Return("Admin")
}
