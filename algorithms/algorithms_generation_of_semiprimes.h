#ifndef ALGORITHMS_GENERATION_OF_SEMIPRIMES_H
#define ALGORITHMS_GENERATION_OF_SEMIPRIMES_H

#include "../save/save_generation_of_semiprimes.h"

void calculate_primes_and_semiprimes(
    unsigned int* primes_array,
    unsigned long number_of_primes,
    BinaryStruct* tuples
);

int compare_by_semiprime(const void* a, const void* b);

#endif
