#!/usr/bin/env python3

import time
import ctypes

MAX_N = 34


def ctypes_fib():
    libc = ctypes.CDLL('./ctypes/libutils.so')
    libc.fibonacci.argstype = ctypes.c_int
    libc.fibonacci.restype = ctypes.c_int
    start_ts = time.time()
    res = libc.fibonacci(MAX_N)
    end_ts = time.time()
    print(f"cpy: {end_ts - start_ts} seconds")
    return res


def fibonacci(n):
    if n < 2:
        return 1
    return fibonacci(n - 1) + fibonacci(n - 2)


def py_fib():
    start_ts = time.time()
    res = fibonacci(MAX_N)
    end_ts = time.time()
    print(f"py: {end_ts - start_ts} seconds")
    return res


def main():
    py_res = py_fib()
    cpy_res = ctypes_fib()
    assert (py_res == cpy_res)


if __name__ == "__main__":
    main()
