#include <stdbool.h>
#include <stdio.h>
#include "save_generation_of_primes.h"

void save_to_file(bool *is_prime, char file_name[], NumberRange numer_range) {
    size_t number_of_primes = 0;
    for (unsigned int i = 0; i < numer_range.b; i++)
        if (is_prime[i]) number_of_primes++;

    FILE* file = fopen(file_name, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open binary file.\n");
        exit(EXIT_FAILURE);
    }

    size_t written = fwrite(is_prime, sizeof(int), number_of_primes, file);
    if (written != number_of_primes) {
        fclose(file);
        fprintf(stderr, "Error: Problem with writting to file.\n");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}
