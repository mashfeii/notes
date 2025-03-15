# 2024-05-30 22:35

`mov` supports some different variations based on weight: `movb` - move 1 byte, `movw` - word (2
bytes), `movl` - long (4 bytes), `movq` - quad (8 bytes)

## Common registers

`%eax`, `%ebx`, `%ecx`, `%edx`, `%esi`, `%edi`, `%ebp`, `%esp`

## Common instructions

```asm
add    SRC, DST        /* DST += SRC */
sub    SRC, DST        /* DST -= SRC */
inc    DST             /* ++DST */
dec    DST             /* --DST */
neg    DST             /* DST = -DST */
mov    SRC, DST        /* DST = SRC */
imul   SRC             /* (%eax,%edx) = %eax * SRC - signed */
mul    SRC             /* (%eax,%edx) = %eax * SRC - unsigned */
and    SRC, DST        /* DST &= SRC */
or     SRC, DST        /* DST |= SRC */
xor    SRC, DST        /* DST ^= SRC */
not    DST             /* DST = ~DST */
cmp    SRC, DST        /* DST - SRC, result is not saved */
test   SRC, DST        /* DST & SRC, result is not saved */
adc    SRC, DST        /* DST += SRC + CF */
sbb    SRC, DST        /* DST -= SRC - CF */
sdq                    /* expands the most significant bit of register %eax by %edx */
```

## Jumps

```asm
jz      label   /* if expression equals zero, ZF == 1 */
jnz     label   /* non-equal zero, ZF == 0 */
jc      label   /* CF == 1 */
jnc     label   /* CF == 0 */
jo      label   /* OF == 1 */
jno     label   /* OF == 0 */
jg      label   /* `>` for signed */
jge     label   /* `>=` for signed */
jl      label   /* `<` for signed */
jle     label   /* `<=` for signed */
ja      label   /* `>` for unsigned */
jae     label   /* `>=` for unsigned  */
jb      label   /* `<` for unsigned */
jbe     label   /* `<=` for unsigned */
```

## GDB Debugger

`break (b) line_number` is a command for break-point setting, `la (layout)` is a general command for some
helpful windows like `la reg` - registers, `la split` - shows commands line by line
`refresh` can be helpful, when GDB windows look weird
For navigation, one can use `next (n)` and `step (s)`, `next` will jump _over_ the function call, while `step`
will jump _into_ it.
Negative numbers lie in the additional code, to convert positive number into negative, one need to
reverse all 0's and 1's and add 1 to reversed number.
