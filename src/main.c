
#include <stdio.h>
#include <stdint.h>

#ifndef BLKSZ
#define BLKSZ 64
#endif

typedef struct List_ {
    uint64_t n;  /* length of payload */
    uint64_t prev; /* 0: none */
    uint64_t next; /* 0: none */
    unsigned char type[BLKSZ];
    /* --- common ---
     *  0x00: empty
     * --- typ[i] for values ---
     *  0x01: uint64
     *  0x02: int64
     *  0x03: double
     *  0x04: string location
     * --- typ[i] for sub-keys ---
     *  0x10: key location 
     */
    uint64_t block[BLKSZ];
    /*
     * --- block[i] for values:  value of indicated type
     * --- block[i] for sub-keys: key location, sorted
     */
} List;

typedef List Values;
typedef List Links;

typedef struct KV_ {
    uint64_t key;
    Values val;
    Links lnk;
} KV;


