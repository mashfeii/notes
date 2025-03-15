package main

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestAdd(t *testing.T) {
	result := Add(int64(1), int64(2))

	assert.IsType(t, int64(3), result)
}
