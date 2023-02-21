#ifndef _ENCODE_H_
#define _ENCODE_H_

#include <stdint.h>

typedef enum {
    NONE,
    CP1251,
    KOI8,
    ISO,
} encode_t;

typedef struct {
    uint32_t data;
    uint8_t  len;
} utf8_t;

utf8_t encode(uint8_t src, encode_t type);

#endif
