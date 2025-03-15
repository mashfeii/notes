# Compilation

## Preprocessing

- Macro substitutions:
  Defined (`#define`, `#undef`)
  Conditional includes (`#ifdef`, `#ifndef`, `#if`, `#endif`, `#else`, `#elifdef`, `#elifndef`, `#elif`)
  Directive `#line`
  Directive `#error`, `#warning`
  Directive `#pragma`
- Substitution of certain macro (`__LINE__`, `__FILE__`, `__DATE__`, `__cplusplus`, and others)
- Результат обработки препроцессором исходного файла называется **единицей трансляции** (translation
  unit)
- Object-like macro `#define <NAME> <CODE>`
- Functional-like macro `#define <NAME>(<PARAMETERS>) <CODE>`
