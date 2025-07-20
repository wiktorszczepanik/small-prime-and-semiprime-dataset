#ifndef SAVE_GENERATION_OF_SEMIPRIMES_H
#define SAVE_GENERATION_OF_SEMIPRIMES_H

typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned long c;
} BinaryStruct;

void save_primes_and_semiprimes(
    BinaryStruct* tuples,
    unsigned long number_of_stucts,
    char output_file[]
);

#endif
