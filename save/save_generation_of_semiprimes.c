#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "save_generation_of_semiprimes.h"

void save_primes_and_semiprimes(
    unsigned int* primes_array,
    unsigned long number_of_semiprimes,
    char output_file[]) {

    FILE* file = fopen(output_file, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open binary file.\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned long i = 0; i < number_of_semiprimes; i++) {
        for (unsigned long j = 0; j < number_of_semiprimes; j++) {
            // unsigned int a = primes_array[i];
            // unsigned int b = primes_array[j];
            // Tuple tuple = {a, b, (unsigned long) a * (unsigned long) b};
            // fwrite(&tuple, sizeof(Tuple), 1, file);
        }
    }
}
