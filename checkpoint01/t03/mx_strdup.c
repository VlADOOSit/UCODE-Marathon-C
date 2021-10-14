#include <stdlib.h>

char* mx_strcpy(char * dst, const char * src)
{
    char *tempptr = dst;
    while (*src) {
        *dst++ = *src++;
    }
    *dst = 0;
    return tempptr;
}

char *mx_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    int i = 0;
    for (; str[i] != '\0'; i++) {
    }
    char *temp = (char *) malloc(i + 1);
    mx_strcpy(temp, str);
    return temp;
}
