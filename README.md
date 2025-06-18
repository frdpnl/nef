# Nef

## introduction

Let's avoid language data structures.


## form

node = key value link

key = string  
value = array of (int | float | string | fun)  
link = array of key  


## implementation notes

- strings are immutable, symbols (humm)
- internalize strings
  later consider directly encoding a few chars in 64 bits?
- look into cache behaviour
- any performance tradeoff is to be exposed as some kind of parameters 
  then automatically tuned/searched per application

