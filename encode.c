#include "encode.h"
#include "encode_tables.h"
#include <stdlib.h>
#include <stddef.h>

const uint8_t UNKNOWN_SYM = 0x3F; // '?'

symbol_t get_table_code(int index, encode_t type)
{
    switch (type) {
        case CP1251: return table_cp1251[index];
        case KOI8:   return table_koi8[index];
        case ISO:    return table_iso[index];
        default:     abort();
    }
}

int get_table_size(encode_t type)
{
    switch (type) {
        case CP1251: return (sizeof(table_cp1251) / sizeof(table_cp1251[0]));
        case KOI8:   return (sizeof(table_koi8) / sizeof(table_koi8[0]));
        case ISO:    return (sizeof(table_iso) / sizeof(table_iso[0]));
        default:     return 0;
    }  
}

uint16_t binary_search(uint8_t src, encode_t type)
{
    int lo = 0;
    int hi = get_table_size(type) - 1;
    while (lo <= hi) {
        size_t mi = (lo + hi) / 2;
        uint8_t mi_code = get_table_code(mi, type).src;
        if (src < mi_code) {
            hi = mi - 1;
        }
        else if (src > mi_code) {
            lo = mi + 1;
        }
        else {
            return get_table_code(mi, type).dst;
        }
    }
    return UNKNOWN_SYM;
}

uint16_t swap(uint16_t bytes)
{
    uint16_t hi = (bytes & 0xff00);
    uint16_t lo = (bytes & 0x00ff);
    return (lo << 8) | (hi >> 8);
}

uint16_t encode(uint8_t src, encode_t type)
{
    if (src < 128) {
        return src;
    }

    uint16_t dst= binary_search(src, type);
    return swap(dst);
}

