#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "algorithms/algorithms_find_row_by_semiprime.h"
#include "setup/set_find_row_by_semiprime.h"

// ./find-by-semiprime { file.bin } { 314 }
int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Error: Incorrect number of files.\n");
        exit(EXIT_FAILURE);
    }
    char* file_name = argv[1];
    if (!does_file_exists(file_name)) {
        fprintf(stderr, "Error: Incorrect file name.\n");
        exit(EXIT_FAILURE);
    }
    char* number = argv[2];
    unsigned long search_number = get_search_number(number);
    size_t number_of_elements = get_number_of_elements(file_name);
    BinaryStruct* tuples = load_semiprimes(file_name, number_of_elements);
    BinaryStruct* output_struct = binary_search(tuples, number_of_elements, search_number);
    if (output_struct == NULL) {
        fprintf(stderr, "Error: Semiprime number not found in dataset.\n");
        exit(EXIT_FAILURE);
    }
    printf("Prime A   : %d\n", output_struct -> a);
    printf("Prime B   : %d\n", output_struct -> b);
    printf("Semiprime : %lu\n", output_struct -> c);
    free(tuples);

    return 0;
}
