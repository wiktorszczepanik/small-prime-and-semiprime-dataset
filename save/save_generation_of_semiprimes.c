#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "save_generation_of_semiprimes.h"

void save_primes_and_semiprimes(
    BinaryStruct* tuples,
    unsigned long number_of_stucts,
    char output_file[]) {

    FILE* file = fopen(output_file, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open binary file.\n");
        exit(EXIT_FAILURE);
    }

    fwrite(tuples, sizeof(BinaryStruct), number_of_stucts, file);
    fclose(file);
}
