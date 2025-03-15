---
id: Header files
aliases: []
tags: []
---

# Fast Notes

> [!NOTE]- Best practice
> When including a header file from the standard library, use the version
> without the `.h` extension if it exists. User-defined header should still use
> a `.h` extension.
> If a header file without a `.h` extension declares names
> into the global namespace, avoid those names, as they may not be available in
> the global namespace on other compilers. Prefer the names declared in the
> `std` namespace instead.

> [!NOTE]- Including header files from other directories
> Using g++, you can use the `-I` option to specify an alternate include
> directory: `g++ -o main -I/source/includes main.cpp`
> There is no space after `-I`.

> [!NOTE]- Best practice
> Each file should explicitly `#include` all of the header files it needs to
> compoile. Do not rely on headers included transitively from other headers.

> [!NOTE]
> To maximize the chance that missing includes will be flagged by compoiler,
> order your `#includes` as follows:
> 1.The paired header file
> 2.Other header from your project
> 3.3rd party library headers
> 4.Standard library headers
> The headers for each grouping should be sorted alphabetically (unless the
> documentation for a 3rd party library instructs you to do otherwise)

## Best Practices

1. Always include header guards
2. Do not define variables and function in header files
3. Give a header file the same name as the source file it's associated with
4. Each header file should have a specific job, and be as independent as
   possible. For example, you might put all your declarations related to
   functionality A in `A.h` and all your declarations related to functionality B in
   `B.h`. That way if you only care about A later, you can just include `A.h` and
   not hit any of the stuff related to B.
5. Be mindful of which headers you need to explicitly include for the
   functionality that you are using in your code files, to avoid inadvertent
   transitive includes.
6. A header file should `#include` any other header containing functionlity it
   needs. Such a `header` should compile successfully when `#included` ainto a
   `.cpp` file by itself.
7. Only `#include` what you need
8. Do not `#include .cpp` files
9. Prefer putting documentation on what something does or how to use it in the
   header. It's more likely to be seen there. Documentation describing how
   something works should remain in the source files.
