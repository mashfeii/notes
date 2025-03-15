package main

import "testing"

func TestPrivateIsEven(t *testing.T) {
	if !privateIsEven(0) {
		t.Error("0 should be even")
	}
	if privateIsEven(1) {
		t.Error("1 should not be even")
	}
}
