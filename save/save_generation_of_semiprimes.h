#ifndef SAVE_GENERATION_OF_SEMIPRIMES_H
#define SAVE_GENERATION_OF_SEMIPRIMES_H

void save_primes_and_semiprimes(
    unsigned int* primes_array,
    unsigned long number_of_primes,
    char output_file[]
);

typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned long c;
} BinaryStruct;

#endif
