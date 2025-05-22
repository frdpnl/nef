
#include <stdint.h>

#ifndef VECSZ
#define VECSZ 64
#endif

typedef struct Vector_ {
    uint64_t n;  /* length of payload */
    unsigned char typ[BLKSZ];
    /* 
     * -- typ[0] describes the raw array
     *  0x00:
     *  0x01: values, 'val
     *  0x02: sub-points, 'sub
     * -- Point.val:
     * 0x00: empty (null)
     * 0x01: next vector defined
     * 0x00: uint64
     * 0x01: int64
     * 0x02: double
     * 0x03: string
     * -- Point.sub:
     * 0x10: key (for 'sub)
     * -- List of vectors:
     * 0xff: chained vector index
     */
    uint64_t raw[BLKSZ];
    /*
     * raw[0] holds flags on the vector
     */
} Vector;

typedef struct Point_ {
    uint64_t key;
    Vector val;
    Vector sub;
} Point;

