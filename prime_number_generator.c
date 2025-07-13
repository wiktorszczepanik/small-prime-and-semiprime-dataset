#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include "algorithms/generation_of_primes.h"


// ./prime-number-generator { 1-32 }
int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Error: Incorrect number of flags.\n");
        exit(EXIT_FAILURE);
    }

    char *entry_range = argv[1];
    if (!is_valid_range(entry_range)) {
        fprintf(stderr, "Error: Incorrect flag setup.\n");
        exit(EXIT_FAILURE);
    }

    BitRange bit_range = set_bit_range(entry_range);
    printf("Selected bit range: <%d-%d>\n", bit_range.a, bit_range.b);

    NumberRange number_range = set_number_range(bit_range);
    printf("Numeric representation: <%u-%u>\n", number_range.a, number_range.b);

    char *file_name = argv[2];
    if (!is_valid_file_name(file_name)) {
        fprintf(stderr, "Error: Incorrect file name.\n");
        exit(EXIT_FAILURE);
    }

    int number_of_primes = estimate_number_of_primes(number_range);
    printf("Estimated number of primes: %d\n", number_of_primes);
    // bool *prime_array = find_primes_eratosthenes();
    // free(prime_array);
    return 0;
}
