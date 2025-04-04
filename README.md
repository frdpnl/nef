# Monotype

A 20% project.

## Introduction

C interface as functions, later sugar-coat in each host language.

Start with basic features, then improve for performance:
- keep design as simple as possible
- improve with a general cache mechanism

## Structure


node = array [ key (string | index), value (int | float | string | node) ]

Root node is omitted.

```
SET x = 2
    node K=/x I=1 V=int:2
    [ 1:x=2, ]
    GET x => 2
    GET 1 => 2
SET A/1 = 2.4
    node K=/A/- I=2/1 V=float:2.4
    [ 1:x=2, 
      2:A=[ 1:-=2.4, ],
    ]
SET A/10 = .4
    node K=/A/- I=2/10 V=float:.4
    [ 1:x=2, 
      2:A=[ 1:-=2.4, 2:-=-, ... 10:-=.4 ],
    ]
```

## Implementation notes

Performance: 
- array: linked small arrays (faster inserts)
- array: hash table (but small/fast)
- array: access by key (string) uses hash table
- array: sequential access uses indices (exploit cache)
- string: internalize

Features:
- how to implement garbage collection? Detect end of scope (block). Depends on host language runtime.

