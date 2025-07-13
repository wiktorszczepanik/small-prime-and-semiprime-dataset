
// Bit range and File name validation
bool is_valid_range(char input_argument[]);
bool is_valid_file_name(char input_file_name[]);

// Setting number range
typedef struct { int a; int b; } BitRange;
typedef struct { unsigned int a; unsigned int b; } NumberRange;
BitRange set_bit_range(char input_argument[]);
NumberRange set_number_range(BitRange bit_range);
