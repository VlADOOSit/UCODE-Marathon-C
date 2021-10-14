#include <stdbool.h>
#include <stdio.h>

bool mx_isdigit(int);
bool mx_isspace(char);

int mx_atoi(const char *str) {
    int i;
    long long n = 0;
    if(str[0] == '-') {
        if(str[1] == 45 || !mx_isdigit(str[1])) {
            return 0;
        }
        for (i = 1; mx_isdigit(str[i]) || mx_isspace(str[i]); i++) {
            if (mx_isspace(str[i])) {
               continue;
            }
            if (!mx_isdigit(str[i]) && !mx_isspace(str[i])) {
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
        for (i = 1; mx_isdigit(str[i]) || mx_isspace(str[i]); i++) {
            if (mx_isspace(str[i])) {
                continue;
            }
            
            n = (n * 10) + (str[i] - '0');
            if (!mx_isdigit(str[i]) && !mx_isspace(str[i])) {
                return 0;
            }
        }
        return (int)n;
    }
    int flag = 1;
    for (i = 0; str[i] == '-' ||  mx_isdigit(str[i]) || mx_isspace(str[i]); i++) {
        if (mx_isspace(str[i])) {
            continue;
        }
        if (str[i] == '-' && mx_isdigit(str[i + 1])) {
            flag = -1;
            continue;
        }
        n = (n * 10) + (str[i] - '0');
       
        if (!mx_isdigit(str[i]) && !mx_isspace(str[i]) && str[i] != '-') {
            return 0;
        }
    }
    while(n > 2147483647) {
        n = n - 2147483648 - 2147483648;
    }
    if (flag == 1) {
        return (int)n;
    }
    else  {
        return -(int)n;
    }
    
}
