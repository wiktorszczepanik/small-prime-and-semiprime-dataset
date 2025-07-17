#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "setup/set_generation_of_semiprimes.h"

// ./semiprime-number-generator { primes.bin } { semiprimes.bin }
int main(int argc, char* argv[]) {
    if (!does_file_exists(argv[1])) {
        fprintf(stderr, "Error: File with primes does not exitst.\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}
