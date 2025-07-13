#include <stdbool.h>
#include <sys/types.h>
#include <math.h>
#include "generation_of_primes.h"

int estimate_number_of_primes(NumberRange number_range) {
    if (number_range.b < 2) return 0;
    if (number_range.a < 2) number_range.a = 2;
    return (int) ((number_range.b / log(number_range.b)) - (number_range.a / log(number_range.a)));
}
