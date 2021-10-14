#include <stdbool.h>
#include <stdio.h>

bool mx_isdigit(int);
bool mx_isspace(char);

int mx_atoi(const char *str) {
    int i;
    long long n = 0;
    if(str[0] == '-') {
        if(str[1] == 45 || !mx_isdigit(str[1]) || mx_isspace(str[1])) {
            return 0;
        }
        for (i = 1; str[i] != '\0'; i++) {
            if (!mx_isdigit(str[i])) {
                return 0;
            }
            n = (n * 10) + (str[i] - '0');
        }
        while(n < -2147483647 - 1) {
            n = n + 2147483647 + 2147483647;
        }
        return -(int)n;
    }
    if(str[0] == '+') {
        for (i = 1; str[i] != '\0'; i++) {
            
            n = (n * 10) + (str[i] - '0');
            if (!mx_isdigit(str[i])) {
                return 0;
            }
        }
        return (int)n;
    }
    for (i = 0; str[i] != '\0'; i++) {
        n = (n * 10) + (str[i] - '0');
        if (!mx_isdigit(str[i])) {
            return 0;
        }
    }
    while(n > 2147483647) {
        n = n - 2147483648 - 2147483648;
    }
    return (int)n;
}
