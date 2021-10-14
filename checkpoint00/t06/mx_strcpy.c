char *mx_strcpy(char *dst, const char *src) {
    char *first = dst;

    while ((*dst++ = *src++) != '\0');

    *dst = '\0';
    return first;
}
