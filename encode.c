#include "encode.h"
#include "encode_tables.h"
#include <stdlib.h>
#include <stddef.h>

const uint8_t UNKNOWN_SYM = 0x3F; // '?'

uint32_t get_utf_data(uint8_t src, encode_t type)
{
    switch (type) {
        case CP1251: return (src < 128) ? src : table_cp1251[src-128];
        case KOI8:   return (src < 128) ? src : table_koi8[src-128];
        case ISO:    return (src < 128) ? src : table_iso[src-128];
        default:     return UNKNOWN_SYM;
    }
}

uint8_t len(uint32_t data)
{
    if      ((data >>  8) == 0)  return 1;
    else if ((data >> 16) == 0)  return 2;
    else if ((data >> 24) == 0)  return 3;
    else                         return 4;
}

uint32_t swap(uint32_t data) 
{
    uint32_t f1 = (data >> 24 & 0xff);
    uint32_t f2 = (data >> 16 & 0xff);
    uint32_t f3 = (data >> 8  & 0xff);
    uint32_t f4 = (data       & 0xff);
    return (f4 << 24) | (f3 << 16) | (f2 << 8) | f1;
}

uint32_t shift(uint32_t data, uint8_t len)
{
    for (uint8_t i=sizeof(data); i!=len; --i) {
        data = (data >> 8);
    }
    return data;
}

utf8_t encode(uint8_t src, encode_t type)
{
    uint32_t utf_data = get_utf_data(src, type);
    uint8_t utf_len = len(utf_data);

    utf_data = swap(utf_data);
    utf_data = shift(utf_data, utf_len);
    
    utf8_t dst = {utf_data, utf_len};
    return dst;
}

