#ifndef SET_FIND_ROW_BY_SEMIPRIME_H
#define SET_FIND_ROW_BY_SEMIPRIME_H

typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned long c;
} BinaryStruct;

bool does_file_exists(char file_name[]);
BinaryStruct* load_semiprimes(char file_name[]);

#endif
