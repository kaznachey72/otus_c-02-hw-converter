#ifndef _UTILS_H_
#define _UTILS_H_

#include "encode.h"
#include <stdio.h>

encode_t get_encode_type(const char *arg_encode);
void convert(FILE *fi, FILE *fo, encode_t type);

#endif
