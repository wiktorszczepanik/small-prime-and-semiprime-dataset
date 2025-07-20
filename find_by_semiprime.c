#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "setup/set_find_by_semiprime.h"

// ./find-by-semiprime { file.bin }
int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error: Incorrect number of files.\n");
        exit(EXIT_FAILURE);
    }
    char* file_name = argv[1];
    if (!does_file_exists(file_name)) {
        fprintf(stderr, "Error: Incorrect file name.\n");
        exit(EXIT_FAILURE);
    }
    BinaryStruct* tuples = load_semiprimes(file_name);
    for (int i = 0; i < 20; i++) {
        printf("{%d, %d, %lu}\n", tuples[i].a, tuples[i].b, tuples[i].c);
    }
    return 0;
}
