# The Fuckscript Esoteric Programming Language 

## About Fuckscript
Fuckscript is an esoteric programming language that is based off of brainfuck. It's more intuitive, with more descriptive keywords, and it shares the same tape size of 30K bytes. Programmers have a lot of memory to work with, so they can design all sorts of applications. Fuckscript is also turing complete. The challenging part of programming in FS is that programmers are not allowed to write comments, the interpreter forbids comments as it makes programming easier.<br/>

## Wiki
https://esolangs.org/wiki/Fuckscript

## What Is An Esoteric Programming Language?
*An esoteric programming language is a programming language designed to test the boundaries of computer programming language design, as a proof of concept, as software art, as a hacking interface to another language, or as a joke.* <a href="https://en.wikipedia.org/wiki/Esoteric_programming_language">Wikipedia</a><br/>

## Installation
1. ``git clone https://github.com/josh0xA/Fuckscript.git``<br/>
2. ``cd Fuckscript``<br/>
3. ``make``<br/>
4. ``./fuckscript my_fuckscript_program.fks``<br/>

## The Language Basics
| Instruction | Description |
| --- | --- |
| `FUCK` | increments the current value of the memory pointer (cell)|
| `FUCKK` | decrements the current value of the memory pointer (cell) |
| `FFUCK` | moves the memory pointer to the next cell |
| `FUCKKK` | moves the memory pointer backwards to the previous cell|
| `FUCKER` | user input, reads a character to stdin |
| `FUCKITY` | outputs current value in the cell to stdout |
| `WHATTHEFUCK` | enters a while loop |
| `IAMFUCKED` | marks the end of the loop |
| `THISISFUCKED` | sets the memory pointer to 0 |

### "Hello World" in Fuckscript
- HelloWorld.fks <br/>
```
FFUCK FUCK FUCK FUCK FUCK FUCK FUCK FUCK FUCK WHATTHEFUCK FUCKKK FUCK FUCK FUCK FUCK FUCK FUCK FUCK FUCK FUCK FFUCK FUCKK IAMFUCKED FUCKKK FUCKITY
FFUCK FUCK FUCK FUCK FUCK WHATTHEFUCK FUCKKK FUCK FUCK FUCK FUCK FUCK FUCK FUCK FFUCK FUCKK IAMFUCKED FUCKKK FUCK FUCKITY
FUCK FUCK FUCK FUCK FUCK FUCK FUCK FUCKITY FUCKITY
FUCK FUCK FUCK FUCKITY
FFUCK FFUCK FUCK FUCK FUCK FUCK FUCK FUCK WHATTHEFUCK FUCKKK FUCK FUCK FUCK FUCK FUCK FUCK FUCK FFUCK FUCKK IAMFUCKED FUCKKK FUCK FUCK FUCKITY
FUCKK FUCKK FUCKK FUCKK FUCKK FUCKK FUCKK FUCKK FUCKK FUCKK FUCKK FUCKK FUCKITY
FFUCK FUCK FUCK FUCK FUCK FUCK FUCK WHATTHEFUCK FUCKKK FUCK FUCK FUCK FUCK FUCK FUCK FUCK FUCK FUCK FFUCK FUCKK IAMFUCKED FUCKKK FUCK FUCKITY
FUCKKK FUCKITY
FUCK FUCK FUCK FUCKITY
FUCKK FUCKK FUCKK FUCKK FUCKK FUCKK FUCKITY
FUCKK FUCKK FUCKK FUCKK FUCKK FUCKK FUCKK FUCKK FUCKITY
FFUCK FFUCK FFUCK FUCK FUCK FUCK FUCK WHATTHEFUCK FUCKKK FUCK FUCK FUCK FUCK FUCK FUCK FUCK FUCK FFUCK FUCKK IAMFUCKED FUCKKK FUCK FUCKITY

```
Output: ``Hello, World!``<br/>

### Sum Two Numbers in Fuckscript
```
FUCKER
FFUCK
FUCKER
FUCKKK
FFUCK
WHATTHEFUCK
  FUCKK
  FUCKKK
  FUCK
  FFUCK
IAMFUCKED
FUCKKK
FUCKITY
```

### License
MIT License <br/>
Copyright (c) 2024 Josh Schiavone

