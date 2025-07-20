#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "setup/set_generation_of_semiprimes.h"
#include "save/save_generation_of_semiprimes.h"
#include "algorithms/generation_of_semiprimes.h"

// ./semiprime-number-generator { primes.bin } { semiprimes.bin }
int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Error: Incorrect number of files.\n");
        exit(EXIT_FAILURE);
    }
    char* primes_file = argv[1];
    if (!does_file_exists(primes_file)) {
        fprintf(stderr, "Error: File with primes does not exitst.\n");
        exit(EXIT_FAILURE);
    }

    unsigned long number_of_semiprimes = cartesian_product_size(primes_file);
    printf("Estimated number of semiprimes:..... %lu\n", number_of_semiprimes);

    char memory_size[50];
    file_size_estimation(number_of_semiprimes * sizeof(BinaryStruct), memory_size);
    printf("Estimated size of the file:......... %s\n", memory_size);

    if (!should_continue()) exit(EXIT_FAILURE);

    unsigned int* primes_array = load_primes(primes_file);
    char* output_file = argv[2];
    unsigned int number_of_primes = primes_counter(primes_file);

    printf("\nAllocating memory for semiprimes.... ");
    BinaryStruct* tuples = malloc(number_of_semiprimes * sizeof(BinaryStruct));

    printf("DONE\nCalculating semiprimes.............. ");
    calculate_primes_and_semiprimes(primes_array, number_of_primes, tuples);

    printf("DONE\nSorting semiprimes.................. ");
    qsort(tuples, number_of_semiprimes, sizeof(BinaryStruct), compare_by_semiprime);

    printf("DONE\nSaving semiprimes................... ");
    save_primes_and_semiprimes(tuples, number_of_semiprimes, output_file);

    printf("DONE\nDeallocating memory................. ");
    free(primes_array);
    free(tuples);
    printf("DONE\n");

    return 0;
}
