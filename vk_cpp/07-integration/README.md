# Python integration with C

**Why?**

- You need speed, and you know that C is much faster
- You need certain C library, and you do not want to implement it in Python
- You need low-level interface of memory and files resources management
- Just since you want to!

## `ctypes`

- Works with DLL (Dynamic link library)
- `ctypes` defines data types compatible with C language
  - `c_bool`
  - `c_char`
  - `c_int`
  - `c_char_p` (pointer)
  - `c_void_p` (void pointer)
- To include library you need:
  - `ctypes.cdll.LoadLibrary('<dll path>')`
  - `ctypes.CDLL('<dll path>')`

## CFFI (C Foreign Function Interface)
