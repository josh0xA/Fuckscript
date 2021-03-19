# The Fuckscript Esoteric Programming Language 

## About Fuckscript
Fuckscript is an esoteric programming that is based off of brainfuck. It's more intuitive, with more descriptive keywords, and it shares the same tape size of 30K bytes. Programmers have a lot of memory to work with, so they can design all sorts of applications. Fuckscript is also turing complete. The challenging part of programming in FS, is that programmers are not allowed to write comments, the interpreter forbids comments as it makes it programming easier.<br/>

## Installation
1. ``git clone https://gitnub.com/josh0xA/fuckscript-.git``<br/>
2. ``cd fuckscript-``<br/>
3. ``make``<br/>
4. ``./fuckscript my_fuckscript_program.fks``<br/>

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

### "Hello World" In Fuckscript
- HellWorld.fks <br/>
```
fuckshiftfront fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckbegin fuckshiftback fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckshiftfront fucksub fuckend fuckshiftback fuckout
fuckshiftfront fuckplus fuckplus fuckplus fuckplus fuckbegin fuckshiftback fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckshiftfront fucksub fuckend fuckshiftback fuckplus fuckout
fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckout fuckout
fuckplus fuckplus fuckplus fuckout
fuckshiftfront fuckshiftfront fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckbegin fuckshiftback fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckshiftfront fucksub fuckend fuckshiftback fuckplus fuckplus fuckout
fucksub fucksub fucksub fucksub fucksub fucksub fucksub fucksub fucksub fucksub fucksub fucksub fuckout
fuckshiftfront fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckbegin fuckshiftback fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckshiftfront fucksub fuckend fuckshiftback fuckplus fuckout
fuckshiftback fuckout
fuckplus fuckplus fuckplus fuckout
fucksub fucksub fucksub fucksub fucksub fucksub fuckout
fucksub fucksub fucksub fucksub fucksub fucksub fucksub fucksub fuckout
fuckshiftfront fuckshiftfront fuckshiftfront fuckplus fuckplus fuckplus fuckplus fuckbegin fuckshiftback fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckplus fuckshiftfront fucksub fuckend fuckshiftback fuckplus fuckout
```
Output: ``Hello, World!``<br/>

### License
MIT License <br/>
Copyright (c) 2021 Josh Schiavone

