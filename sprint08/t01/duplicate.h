#ifndef HEAD
#define HEAD

#include <stdlib.h>

int *mx_copy_int_arr(const int *, int);

typedef struct starr {
    int *arr;
    int size;
}    tmarr;

tmarr *mx_del_dup_sarr(tmarr *);

#endif
