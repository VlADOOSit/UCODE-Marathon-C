#include <stdlib.h>

char* mx_nbr_to_hex(unsigned long nbr) {
    char *str = (char *) malloc(20 + 1);
    for (int i = 0; i < 20; i++) {
        str[i] = '\0';
    }
    char *arr = str;
    int i = 0;
    int len = 0;
    while(nbr != 0) {
        int temp = 0;
        temp = nbr % 16;
        if(temp < 10) {
            arr[i] = temp + 48;
            i++;
        }
        else {
            arr[i] = temp + 87;
            i++;
        }
        nbr = nbr / 16;
        len++;
    }
    if (len < 1) {
        return NULL;
    }
    char *str1 = (char *) malloc(len + 1);
    for (int i = 0; i < len; i++) {
        str1[i] = '\0';
    }
    char *result = str1;
    for(int i =0; i < len; i++){
        result[i] = arr[len - i - 1];
    }
    return result;
}
