
#include <stdint.h>

#ifndef VECSZ
#define VECSZ 64
#endif

// TODO
// interned strings, for key, string locations
// interned locations, memory pool, for chained vector
// test coverage

typedef struct Vector_ {
    uint64_t n;  /* length of payload */
    unsigned char typ[VECSZ];
    /* 
     * --- typ[0] describes the full raw array ---
     *  0x00: empty
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

typedef Vector Values;
typedef Vector Subkeys;

typedef struct Point_ {
    uint64_t key;
    Values val;
    Subkeys sub;
} Point;

