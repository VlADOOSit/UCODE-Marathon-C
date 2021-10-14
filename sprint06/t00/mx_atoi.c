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
        for (i = 1; (mx_isdigit(str[i]) && !mx_isspace(str[i])); i++) {
            n = (n * 10) + (str[i] - '0');
        }
        while(n < -2147483647 - 1) {
            n = n + 2147483647 + 2147483647;
        }
        return -(int)n;
    }
    for (i = 0; (mx_isdigit(str[i]) && !mx_isspace(str[i])); i++) {
        n = (n * 10) + (str[i] - '0');
    }
    while(n > 2147483647) {
        n = n - 2147483648 - 2147483648;
    }
    return (int)n;
}

int main() {
    char str[] = "-1214142129fsf";
    printf("%d", mx_atoi(str));
    return 0;
}
