#ifndef _ENCODE_H_
#define _ENCODE_H_

#include <stdint.h>

typedef enum {
    NONE,
    CP1251,
    KOI8,
    ISO,
} encode_t;

uint16_t encode(uint8_t src, encode_t type);

#endif
