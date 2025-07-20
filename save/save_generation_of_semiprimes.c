#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "save_generation_of_semiprimes.h"

void save_primes_and_semiprimes(
    unsigned int* primes_array,
    unsigned long number_of_primes,
    char output_file[]) {

    FILE* file = fopen(output_file, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open binary file.\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned long i = 0; i < number_of_primes; i++) {
        for (unsigned long j = i; j < number_of_primes; j++) {
            unsigned int a = primes_array[i], b = primes_array[j];
            BinaryStruct tuple = {a, b, (unsigned long) a * b};
            fwrite(&tuple, sizeof(BinaryStruct), 1, file);
        }
    }
}
