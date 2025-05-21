
#include <stdint.h>

#define BLKSZ 64

typedef struct Block_ {
    unsigned char typ[BLKSZ];
    uint64_t raw[BLKSZ];
} Block;

typedef struct Point_ {
    uint64_t key;
    Block val;
    Block sub;
} Point;

