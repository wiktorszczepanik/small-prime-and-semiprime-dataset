#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "generation_of_semiprimes.h"

void calculate_primes_and_semiprimes(
    unsigned int* primes_array,
    unsigned long number_of_primes,
    BinaryStruct* tuples) {

        if (tuples == NULL) {
            free(tuples);
            free(primes_array);
            fprintf(stderr, "Error: Cannot allocate the memory.\n");
            exit(EXIT_FAILURE);
        }

        unsigned long index = 0;
        for (unsigned long i = 0; i < number_of_primes; i++) {
            for (unsigned long j = i; j < number_of_primes; j++) {
                unsigned int a = primes_array[i], b = primes_array[j];
                unsigned long c = (unsigned long) a * b;
                tuples[index++] = (BinaryStruct) {a, b, c};
            }
        }

}

int compare_by_semiprime(const void* first, const void* second) {
    const BinaryStruct* a = (const BinaryStruct*) first;
    const BinaryStruct* b = (const BinaryStruct*) second;

    if (a -> c < b -> c) return -1;
    if (a -> c > b -> c) return 1;
    return 0;
}
