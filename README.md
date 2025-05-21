# monotone

## introduction

Let's avoid language-specific data structures, and instead rely on a common, regular, data structure across several languages.


## form

node = key value link

key = string  
value = array of (int | float | string)  
link = array of key  


## implementation comments

- strings are immutable, symbols (humm)
- internalize strings
  later consider directly encoding a few chars in 64 bits?
- look into cache behaviour
- array is a sequence of linked arrays, fixed size
  hopefully good balance between inserts and access
- any performance tradeoff is to be exposed as some kind of parameters 
  then automatically tuned/searched per application

## next

**Pattern matching**

**Pretty print**

**Garbage collection** Detect end of scope (block). Depends on host language runtime.

