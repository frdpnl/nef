
#include <stdint.h>

#ifndef VECSZ
#define VECSZ 64
#endif

// TODO typedef to distinguish the 2 vectors...

typedef struct Vector_ {
    uint64_t n;  /* length of payload */
    unsigned char typ[VECSZ];
    /* 
     * --- typ[0] describes the full raw array ---
     *  0x00: empty
     *  0x_1: type is values, 'val
     *  0x_2: type is sub-points, 'sub
     *  0x10: is there a chained vector
     * --- typ[i] for values ---
     *  0x00: empty (null)
     *  0x01: uint64
     *  0x02: int64
     *  0x03: double
     *  0x04: string location
     * --- typ[i] for sub-keys ---
     *  0x00: empty (null)
     *  0x10: key location 
     */
    uint64_t raw[VECSZ];
    /*
     * --- raw[0] next vector location ---
     * --- raw[i] for values:  value of indicated type
     * --- raw[i] for sub-keys: key location
     */
} Vector;

typedef struct Point_ {
    uint64_t key;
    Values val;
    Subkeys sub;
} Point;

