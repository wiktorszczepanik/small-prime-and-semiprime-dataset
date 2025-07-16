#include <stdbool.h>
#include <stdio.h>
#include "save_generation_of_primes.h"

void save_to_file(bool *is_prime, char file_name[], NumberRange numer_range) {
    FILE* file = fopen(file_name, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open binary file.\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = numer_range.a; i < numer_range.b; i++) {
        printf("%s\n", is_prime[i] ? "true" : "false");
    }
    fclose(file);
}
