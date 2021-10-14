#include <stdlib.h>

int mx_strlen(const char*);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strdup(const char *str);
char *mx_strnew(const int size);
void mx_strdel(char **str);

char *mx_concat_words(char **words) {
    char *result = mx_strdup(words[0]);
    for (int i = 1; words[i] != NULL; i++) {
        char *temp = mx_strjoin(result, " ");
        mx_strdel(&result);
        result = mx_strjoin(temp, words[i]);
        mx_strdel(&temp);
    }
    return result;
}
