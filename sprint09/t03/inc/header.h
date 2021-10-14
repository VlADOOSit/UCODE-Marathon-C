#ifndef HEADER_h
#define HEADER_h
#include <stdbool.h>

int mx_atoi(const char *str);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char* s);
int mx_strcmp(const char *s1, const char *s2);
char* mx_strcpy(char * dst, const char * src);
int mx_strlen(const char* s);
bool mx_isspace(char c);
bool mx_isdigit(int c);

#endif
