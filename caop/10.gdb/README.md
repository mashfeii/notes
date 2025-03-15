# Additional notes on debugger GDB

For comfort representation one can use `layout (la) src`, that will show source code
`refresh` has shortcut `Ctrl + l`
`next (n)` jumps to the next operation
`Enter` repeats the last entered command
Breakpoint can be set not only on lines, but on functions (by name) as well
`bt` can show the call stack (with action frames), then move through stack with `up` or `down`

To make GDB watches for variable by itself, there is `watch` command, with `countinue (c)` it will
show every change in variable value, also, command can be conditional: `watch i if i == 0`
Reverse debugging works with `target record-full`, so, one can navigate not only forwards, but
backwards as well: `reverse step (rs)`, `reverse continue (rc)`, `reverse next (rn)`

`GDB` has command `set print pretty on` that supports custom python printers [in the following
syntax](./custom_printer.py)

`gdb` also supports config file `.gdbinit`
