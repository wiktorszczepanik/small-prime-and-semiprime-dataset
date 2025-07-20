#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "set_generation_of_semiprimes.h"

bool does_file_exists(char file_name[]) {
    FILE* file;
    if (file = fopen(file_name, "r")) {
        fclose(file);
        return true;
    }
    return false;
}

unsigned long cartesian_product_size(char file_name[]) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot read binary file.\n");
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END);
    long entry_file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    fclose(file);

    unsigned int number_of_elements = entry_file_size / sizeof(unsigned int);
    unsigned long cartesian_product_size = pow(number_of_elements, 2);
    return cartesian_product_size;
}

void file_size_estimation(unsigned long size, char* mem_size) {
    if (size < 1024) sprintf(mem_size, "%ld B", size);
    else if (size < 1048576) sprintf(mem_size, "%ld KB", size / 1024);
    else if (size < 1073741824) sprintf(mem_size, "%ld MB", size / 1048576);
    else sprintf(mem_size, "%ld GB", size / 1073741824);
}

bool should_continue() {
    printf("\nWould you like to proceed?\n");
    printf("[Y/n] ");
    char input; scanf("%c", &input);
    return (input == 'Y' || input == 'y') ? true : false;
}

unsigned int* load_primes(char file_name[]) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot read binary file.\n");
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    size_t number_of_elements = file_size / sizeof(unsigned int);
    unsigned int* primes_array = (unsigned int*) malloc(
        number_of_elements * sizeof(unsigned int)
    );
    fread(primes_array, sizeof(unsigned int), number_of_elements, file);
    fclose(file);
    return primes_array;
}
