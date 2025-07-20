#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "set_find_row_by_semiprime.h"

bool does_file_exists(char file_name[]) {
    FILE* file;
    if (file = fopen(file_name, "r")) {
        fclose(file);
        return true;
    }
    return false;
}

BinaryStruct* load_semiprimes(char file_name[]) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot read binary file.\n");
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END);
    unsigned long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    size_t number_of_elements = file_size / sizeof(BinaryStruct);
    BinaryStruct* semiprimes_array = (BinaryStruct*) malloc(
        number_of_elements * sizeof(BinaryStruct)
    );
    fread(semiprimes_array, sizeof(BinaryStruct), number_of_elements, file);
    fclose(file);
    return semiprimes_array;
}
