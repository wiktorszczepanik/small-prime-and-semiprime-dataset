#ifndef SET_GENERATION_OF_SEMIPRIMES_H
#define SET_GENERATION_OF_SEMIPRIMES_H

bool does_file_exists(char file_name[]);
unsigned long cartesian_product_size(char file_name[]);
unsigned int primes_counter(char file_name[]);
void file_size_estimation(unsigned long size, char* mem_size);
bool should_continue();
unsigned int* load_primes(char file_name[]);

#endif
