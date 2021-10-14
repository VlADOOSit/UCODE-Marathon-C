#include "file_to_str.h"

char *mx_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    char *temp = mx_strnew(mx_strlen(str));
    mx_strcpy(temp, str);
    return temp;
}
