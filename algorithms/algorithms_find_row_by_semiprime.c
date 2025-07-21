#include <stdbool.h>
#include "algorithms_find_row_by_semiprime.h"

BinaryStruct* binary_search(BinaryStruct* tuples, unsigned long length, unsigned long key) {
    unsigned long left = 0;
    unsigned long right = length - 1;
    while (left <= right) {
        unsigned long mid = left + (right - left) / 2;
        if (tuples[mid].c == key) return &tuples[mid];
        if (tuples[mid].c > key) right = mid - 1;
        else left = mid + 1;
    }
    return NULL;
}
