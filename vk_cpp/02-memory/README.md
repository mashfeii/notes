# Pointers

Default pointers have several problems:

- Pointer does not tell to which object it points: either single or array
- Pointer does not tell one should he delete it after usage or not
- From first points, one can not know which method to use: `delete` or `delete[]`
- Usually, one can not know is pointer valid

So, to solve these problems there are "smart-pointers":

- `const cast`
  removing `const` modification, let modify the value under it
  `int& alias = const_cast<int&>(arg);`
- `static_cast`
  avoids implicit cast, casting can be checked during _compilation_
- `reinterpret_cast`
  reads bits of one type as bits of another
- `dynamic_cast`
  tries to cast child class to parent, otherwise returns `nullptr`
