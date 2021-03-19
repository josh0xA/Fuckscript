# The Fuckscript Esoteric Programming Language 

## About Fuckscript
Fuckscript is an esoteric programming that is based off of brainfuck. It's more intuitive, with more descriptive keywords, and it shares the same tape size of 30K bytes. Programmers have a lot memory to work with, to design all sorts of applications. Fuckscript is also turing complete. The challenging part of programming in FS, is that programmers are not allowed to write comments, the interpreter forbids comments as it makes it programming easier.<br/>

## The Language Basics
| Instruction | Description |
| --- | --- |
| `fuckplus` | increments the current value of the memory pointer (cell)|
| `fucksub` | decrements the current value of the memory pointer (cell) |
| `fuckshiftfront` | moves the memory pointer to the next cell |
| `fuckshiftback` | moves the memory pointer backwards to the previous cell|
| `fuckin` | user input, reads a character to stdin |
| `fuckout` | outputs current value in the cell to stdout |
| `fuckbegin` | enters a while loop |
| `fuckend` | marks the end of the loop |
| `fuckset` | sets the memory pointer to 0 |

