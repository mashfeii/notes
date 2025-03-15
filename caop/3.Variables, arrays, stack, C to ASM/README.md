# 2024-06-03 02:19

## Stack

Stack is consistent "array" of memory (usually, 8 Mb) that grows up, special register `%esp` - stack pointer, holds
current position on the stack, `+` to that pointer moves it up, addressed goes in decreasing memory
order, so top of the stack equals zero address (it can not be increased more - stack overflow).

> [!NOTE]+ Useful shell command
> `ulimit` - shell command, that provides access to available system resources (for modifying as
> well)

## Call agreement (соглашение о вызовах)

When calling a function there is a set of rules (agreements) such that describes which registers one
can change, how to pass arguments and so on, one of them is `cdelc`

### Registers in agreement `cdelc`

**callee-saved** (called program expect that values after its calling won't change)

```asm
%ebp, %ebx, %esi, %edi, %esc
```

**caller-saved** (called program _do not_ hope that values in register after its call will stay
unchanged)

```asm
%eax, %edx, %ecx
```

### Return value

Return value lies in register `%eax`
