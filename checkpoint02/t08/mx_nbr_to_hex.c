#include <stdlib.h>

char *mx_strnew(const int size) {
    int i;
    char *temp;

    if (size < 0)
        return (char *)0;
    temp = malloc(size+1);
    for (i = 0; i < size+1; i++) {
        temp[i]='\0';
    }
    return temp;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    int i = 0;
    int j;
    unsigned long number = nbr;
    char *temp;

    while( nbr > 0) {
        i++;
        nbr /= 16;
    }
    j = (i)*sizeof(char);
    temp = mx_strnew(j);
    while( number > 0) {
        temp[i-1] = "0123456789abcdef"[number % 16];
        i--;
        number /= 16;
    } 
    temp[j] = (char)0;
    return temp;
}
