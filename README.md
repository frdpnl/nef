# Monotype

A 20% project.

## Introduction

C interface as functions, later sugar-coat in each host language.

Start with basic features, then improve for performance:
- keep design as simple as possible
- improve with a general cache mechanism

## Structure


node = array [ key (string | index), value (int | float | string | node) ]

Root node omitted.
```
SET x = 2
    node K="x" I=1 V=int:2
    GET x => 2
    GET 1 => 2


```

## Implementation notes

Performance: 
- array: linked small arrays (faster inserts)
- string: internalize

Features:
- how to implement garbage collection?
