#ifndef SET_FIND_ROW_BY_SEMIPRIME_H
#define SET_FIND_ROW_BY_SEMIPRIME_H

#include <stdio.h>

typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned long c;
} BinaryStruct;

bool does_file_exists(char file_name[]);
size_t get_number_of_elements(char file_name[]);
unsigned long get_search_number(char search_number[]);
BinaryStruct* load_semiprimes(char file_name[], size_t number_of_elements);

#endif
