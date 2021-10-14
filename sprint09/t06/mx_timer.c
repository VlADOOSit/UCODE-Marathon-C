#include <time.h>
#include <stdlib.h>

double mx_timer(void(*f)()) {
    if (clock() < 0) {
        return -1;
    }
    if (*f == NULL) {
        return -1;
    }
    clock_t start_t, end_t;
    start_t = clock();
    f();
    end_t = clock();
    return (double)(end_t - start_t) / CLOCKS_PER_SEC;
}
