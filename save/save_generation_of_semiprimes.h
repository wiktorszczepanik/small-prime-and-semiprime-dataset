#ifndef SAVE_GENERATION_OF_SEMIPRIMES_H
#define SAVE_GENERATION_OF_SEMIPRIMES_H

typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned long c;
} Tuple;

void save_primes_and_semiprimes(
    unsigned int* primes_array,
    unsigned long number_of_semiprimes,
    char output_file[]
);

#endif
