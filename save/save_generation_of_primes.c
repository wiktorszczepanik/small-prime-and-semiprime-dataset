#include <stdbool.h>
#include <stdio.h>
#include "save_generation_of_primes.h"

//...
void save_to_file(bool *is_prime, char file_name[], NumberRange number_range) {
    // size_t number_of_primes = 0;
    // for (unsigned int i = 0; i < number_range.b; i++)
    //     if (is_prime[i]) number_of_primes++;

    FILE* file = fopen(file_name, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open binary file.\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < number_range.b; i++) {
        if (is_prime[i]) {
            size_t written = fwrite(&i, sizeof(unsigned int), 1, file);
            if (written != 1) {
                fclose(file);
                fprintf(stderr, "Error: Problem with writting to file.\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
}
