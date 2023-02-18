#include "utils.h"
#include <string.h>

encode_t get_encode_type(const char *arg_encode)
{
    encode_t result = NONE;
    
    if (strncmp(arg_encode, "cp1251", 6)==0 || strncmp(arg_encode, "CP1251", 6)==0) {
        result = CP1251;
    }
    else if (strncmp(arg_encode, "koi8", 4)==0 || strncmp(arg_encode, "KOI8", 4)==0) {
        result = KOI8;
    }
    else if (strncmp(arg_encode, "iso", 3)==0 || strncmp(arg_encode, "ISO", 3)==0) {
        result = ISO;
    }

    return result;
}

void convert(FILE *fi, FILE *fo, encode_t type)
{
    int src;
    while ((src = fgetc(fi)) != EOF) {
        uint16_t dst = encode(src, type);
        fwrite(&dst, 1, sizeof(dst), fo);
    }
}
