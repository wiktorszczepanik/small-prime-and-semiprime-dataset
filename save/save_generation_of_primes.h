#ifndef SAVE_GENERATION_OF_PRIMES_H
#define SAVE_GENERATION_OF_PRIMES_H

#include <stdbool.h>
#include "../setup/set_generation_of_primes.h"

void save_to_file(bool *is_prime, char file_name[], NumberRange number_range);

#endif
