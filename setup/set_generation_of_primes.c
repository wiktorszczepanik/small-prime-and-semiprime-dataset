#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include "set_generation_of_primes.h"

bool is_valid_range(char input_argument[]) {
    int len = strlen(input_argument);
    int dash_index; int dash_counter = 0;
    for (int i = 0; i < len; i++) {
        if ((input_argument[i] > 47 && input_argument[i] < 58) || input_argument[i] == 45) {
            if (input_argument[i] == 45) {
                dash_index = i;
                dash_counter++;
            }
        } else return false;
    }
    if (dash_counter != 1) return false;
    if (input_argument[0] < 49 || input_argument[0] > 57) return false;
    if (input_argument[dash_index + 1] < 49 || input_argument[dash_index + 1] > 57) return false;
    return true;
}

BitRange set_bit_range(char input_argument[]) {
    int len = strlen(input_argument);
    int split_index;
    for (int i = 0; i < len; i++)
        if (input_argument[i] == 45)
            split_index = i;

    // Get first number
    char num1[split_index + 1];
    for (int i = 0; i < split_index; i++)
        num1[i] = input_argument[i];
    num1[split_index + 1] = '\0';

    // Get second number
    int secpart_index = len - split_index;
    char num2[secpart_index];
    for (int i = 0; i < secpart_index - 1; i++)
        num2[i] = input_argument[i + split_index + 1];
    num2[secpart_index] = '\0';

    BitRange range;
    int first_num = atoi(num1);
    if (first_num > 0 && first_num <= 32)
        range.a = atoi(num1);
    else {
        fprintf(stderr, "Error: Incorrect first number bit size.\n");
        exit(EXIT_FAILURE);
    }
    int second_num = atoi(num2);
    if (second_num > 0 && second_num <= 32)
        range.b = atoi(num2);
    else {
        fprintf(stderr, "Error: Incorrect second number bit size.\n");
        exit(EXIT_FAILURE);
    }
    if (first_num > second_num) {
        fprintf(stderr, "Error: First number representing bit size is bigger then second number.\n");
        exit(EXIT_FAILURE);
    }
    return range;
}

NumberRange set_number_range(BitRange bit_range) {
    NumberRange number_range;
    number_range.a = 0; number_range.b = 0;

    for (int i = 0; i < bit_range.a; i++)
        number_range.a += (1U << i);
    for (int i = 0; i < bit_range.b; i++)
        number_range.b += (1U << i);

    return number_range;
}

bool is_valid_file_name(char input_file_name[]) {
    int len_of_file = strlen(input_file_name);
    char incorrect_chars[] = {'/', '>', '<', '|', ':', '&'};
    int len_of_incorrect_chars = strlen(incorrect_chars);
    for (int i = 0; i < len_of_file; i++) {
        for (int j = 0; j < len_of_incorrect_chars; j++)
            if (input_file_name[i] == incorrect_chars[j])
                return false;
    }
    return true;
}

char* file_size_estimation(int number_of_primes) {
    int size = number_of_primes * sizeof(int);
    char mem_size[20];
    // if (size < 1024) sprintf(mem_size, "%d B",);
    // else if (size < 1048576) mem_size = "MB";
    // ...
}

bool should_continue() {
    printf("\nConsidering the above information, would you like to proceed?\n");
    printf("[Y/n] ");
    char input; scanf("%c", &input);
    return (input == 'Y' || input == 'y') ? true : false;
}

bool* int_bool_array(size_t size_for_memory) {
    bool* is_prime_array = (bool*) malloc(size_for_memory * sizeof(bool));
    if (is_prime_array == NULL) {
        fprintf(stderr, "Error: Problem with memory allcation.\n");
        exit(EXIT_FAILURE);
    }
    for (unsigned int i = 0; i < size_for_memory; i++)
        is_prime_array[i] = true;

    return is_prime_array;
}
