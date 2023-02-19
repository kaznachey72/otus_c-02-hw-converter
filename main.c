#include "utils.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 4) {
        printf("USAGE: %s input_file encode_type output_file\n", argv[0]);
        return 1;
    }

    encode_t type = get_encode_type(argv[2]);
    if (type == NONE) {
        printf("valid encode types: CP1251, ISO, KOI8\n");
        return 1;
    }

    FILE *fi = fopen(argv[1], "rb");
    if (!fi) {
        printf("ERROR: input file open error\n");
        return 1;
    }

    FILE *fo = fopen(argv[3], "wb");
    if (!fo) {
        printf("ERROR: output file open error\n");
        return 1;
    } 

    convert(fi, fo, type);
    
    fclose(fi);
    fclose(fo);

    return 0;
}
