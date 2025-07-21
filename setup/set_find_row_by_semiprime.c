#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "set_find_row_by_semiprime.h"

bool does_file_exists(char file_name[]) {
    FILE* file;
    if (file = fopen(file_name, "r")) {
        fclose(file);
        return true;
    }
    return false;
}

unsigned long get_search_number(char search_number[]) {
    char* end_ptr;
    unsigned long number = strtoul(search_number, &end_ptr, 10);
    if (end_ptr == search_number) {
        fprintf(stderr, "Error: Incorrect format of search number.\n");
        exit(EXIT_FAILURE);
    }
    if (number == ULONG_MAX && end_ptr != search_number) {
        fprintf(stderr, "Error: Number out of range.\n");
        exit(EXIT_FAILURE);
    }
    return number;
}

size_t get_number_of_elements(char file_name[]) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot read binary file.\n");
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END);
    unsigned long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    fclose(file);
    return file_size / sizeof(BinaryStruct);
}

BinaryStruct* load_semiprimes(char file_name[], size_t number_of_elements) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot read binary file.\n");
        exit(EXIT_FAILURE);
    }
    BinaryStruct* semiprimes_array = (BinaryStruct*) malloc(
        number_of_elements * sizeof(BinaryStruct)
    );
    fread(semiprimes_array, sizeof(BinaryStruct), number_of_elements, file);
    fclose(file);
    return semiprimes_array;
}
