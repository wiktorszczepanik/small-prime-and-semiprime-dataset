#ifndef ALGORITHMS_GENERATION_OF_PRIMES_H
#define ALGORITHMS_GENERATION_OF_PRIMES_H

#include "../setup/set_generation_of_primes.h"

int estimate_number_of_primes(NumberRange number_range);
void find_primes_eratosthenes(bool *is_prime, unsigned int size);

#endif
