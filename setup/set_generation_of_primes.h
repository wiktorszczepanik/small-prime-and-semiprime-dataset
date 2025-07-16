#ifndef SET_GENERATION_OF_PRIMES_H
#define SET_GENERATION_OF_PRIMES_H

#include <stdlib.h>

// Bit range and File name validation
bool is_valid_range(char input_argument[]);
bool is_valid_file_name(char input_file_name[]);
char* file_size_estimation(int number_of_primes);
bool should_continue();
bool* int_bool_array(size_t size_for_memory);

// Setting number range
typedef struct { int a; int b; } BitRange;
typedef struct { unsigned int a; unsigned int b; } NumberRange;
BitRange set_bit_range(char input_argument[]);
NumberRange set_number_range(BitRange bit_range);

#endif
