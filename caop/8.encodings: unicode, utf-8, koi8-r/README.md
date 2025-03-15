# Encodings

All the characters use special table for representing their code in system, the main one is ASCII
table, but it responds for displaying only English alphabet, thus, another encoding KOI8-R was
developed, it contains first 128 ASCII symbols, but extend it with Russian ones (that copies the
position of corresponding English letter)

`utf-8` contains in its structure BOI - additional binary code for character representation that
contains the number of bytes in char encoding

For example: to encode ё into utf-8 one need to convert its code to binary (0451 → 01000101001),
then choose the right number of bytes (2) and rewrite representation into (110100011001000 = D191 in hex)
