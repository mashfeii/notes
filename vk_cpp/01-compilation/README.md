`objdump -t execution_name` - special command to retrieve symbols table from binary file
for example, in C symbols are the same as names in source code, but C++ supports overloads, since
that, its symbols are harder to understand than in C
possible analogue is `readelf --all binary_name`, also can show symbols table
