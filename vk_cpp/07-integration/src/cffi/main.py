#!/usr/bin/env python3

from cffi import CFFI 


def main():
    cffi = CFFI()
    lib = cffi.dlopen('./libutils.so')
    cffi

if __name__ == "__main__":
    main();
