#include <stdbool.h>
#include <sys/types.h>
#include <math.h>
#include "algorithms_generation_of_primes.h"

int estimate_number_of_primes(NumberRange number_range) {
    if (number_range.b < 2) return 0;
    if (number_range.a < 2) number_range.a = 2;
    return (int) ((number_range.b / log(number_range.b)) - (number_range.a / log(number_range.a)));
}

void find_primes_eratosthenes(bool *is_prime, unsigned int size) {
    unsigned int j = 0;
    for (unsigned int i = 2; i < sqrt(size); i++) {
        if (is_prime[i]) {
            j = pow(i, 2);
            while (j <= size) {
                is_prime[j] = false;
                j = j + i;
            }
        }
    }
}
