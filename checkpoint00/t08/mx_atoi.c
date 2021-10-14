#include <stdbool.h>

int mx_atoi(const char *str) {
    int i;
    long long n = 0;
    if(str[0] == '-') {
        if(str[1] == 45 || !(str[1] >= 48 && str[1] <= 57) || (str[1] == ' ' || str[1] == '\t' || str[1] == '\n' || str[1] == '\v' || str[1] == '\f' || str[1] == '\r') ) {
            return 0;
        }
        for (i = 1; (str[i] >= 48 && str[i] <= 57) && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r'); i++) {
            n = (n * 10) + (str[i] - '0');
        }
        while(n < -2147483647 - 1) {
            n = n + 2147483647 + 2147483647;
        }
        return -(int)n;
    }
    for (i = 0; ((str[i] >= 48 && str[i] <= 57) && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')); i++) {
        n = (n * 10) + (str[i] - '0');
    }
    while(n > 2147483647) {
        n = n - 2147483648 - 2147483648;
    }
    return (int)n;
}
