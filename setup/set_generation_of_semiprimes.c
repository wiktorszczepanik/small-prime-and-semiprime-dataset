#include <stdbool.h>
#include <stdio.h>
#include "set_generation_of_semiprimes.h"

bool does_file_exists(char input_argument[]) {
    FILE* file;
    if (file = fopen(input_argument, "r")) {
        fclose(file);
        return true;
    }
    return false;
}

bool* load_primes(char input_argument[]) {
    unsigned int* primes_set;
    //
}
