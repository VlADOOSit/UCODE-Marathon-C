#include "header.h"

void mx_printint(int n) {
    if (n == 0) {
        mx_printchar(48);
        return;
    }
    if (n < 0) {
        mx_printchar(45);
        n *= -1;
    }
    int temp = n;
    int counter = 0;
    while(temp != 0) {
        temp = temp / 10;
        counter++;
    }
    int array[counter];
    int count_mass = 0;
    while(n != 0) { 
        array[count_mass] = n % 10;
        n /= 10;
        count_mass++;
    }
    for(int j = count_mass - 1; j >= 0; j--) {
        mx_printchar(array[j] + 48);
    }
}
