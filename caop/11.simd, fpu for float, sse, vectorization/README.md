# FPU

FPU (Floating Point Unit) - is a separate processor core for floating point calculations only
Such unit has up to 7 registers 80 bites each, that are organized into [own stack](./compute_float.S) 

In modern realization, we got additional register for floating points values, as [in example](./compute_floats_modern.S) (0 - 7 for 32 bits systems, 0 - 15 for 64 ones) 

`xmm` register is 128 bites weight
