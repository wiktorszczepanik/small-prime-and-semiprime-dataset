#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>

// Bit range and File name validation
bool is_valid_range(char input_argument[]);
bool is_valid_file_name(char input_file_name[]);

// Setting number range
typedef struct { int a; int b; } BitRange;
typedef struct { unsigned int a; unsigned int b; } NumberRange;
BitRange set_bit_range(char input_argument[]);
NumberRange set_number_range(BitRange bit_range);

// Prime numbers generating algorithms
void sieve_of_atkin(NumberRange number_range, char file_name[]);


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
    return 0;
}

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

void sieve_of_atkin(NumberRange number_range, char file_name[]) {
    //
}
