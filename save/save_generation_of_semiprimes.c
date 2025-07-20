#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "save_generation_of_semiprimes.h"

void save_primes_and_semiprimes(
    unsigned int* primes_array,
    unsigned long number_of_primes,
    unsigned long number_of_stucts,
    char output_file[]) {

    BinaryStruct* tuples = malloc(number_of_stucts * sizeof(BinaryStruct));
    if (tuples == NULL) {
        free(tuples);
        free(primes_array);
        fprintf(stderr, "Error: Cannot allocate the memory.\n");
        exit(EXIT_FAILURE);
    }

    unsigned long index = 0;
    for (unsigned long i = 1; i < number_of_primes; i++) {
        for (unsigned long j = i; j < number_of_primes; j++) {
            unsigned int a = primes_array[i], b = primes_array[j];
            unsigned long c = (unsigned long) a * b;
            tuples[index++] = (BinaryStruct) {a, b, c};
        }
    }

    FILE* file = fopen(output_file, "wb");
    if (file == NULL) {
        free(tuples);
        free(primes_array);
        fprintf(stderr, "Error: Cannot open binary file.\n");
        exit(EXIT_FAILURE);
    }

    fwrite(tuples, sizeof(BinaryStruct), number_of_stucts, file);
    fclose(file);
    free(tuples);
}
