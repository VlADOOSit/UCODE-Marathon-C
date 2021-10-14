#include <stdbool.h>
#include <stdio.h>

int mx_comparator(const int *arr, int size, int x, bool (*compare)(int, int)) {
    int i;
    for (i = 0; i < size; i++) {
        if (compare(arr[i], x)) {
            return i;
        }
    }
    return -1;
}

bool equal_nums(int a, int b) {
    return a == b;
}
