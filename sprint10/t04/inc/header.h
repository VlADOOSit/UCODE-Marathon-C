#ifndef HEADER_h
#define HEADER_h

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <string.h>
#include <errno.h>

void printall(int len, int str, int characters, int check, char *argv);
int mx_atoi(const char *str);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char* s);
int mx_strcmp(const char *s1, const char *s2);
char* mx_strcpy(char * dst, const char * src);
int mx_strlen(const char* s);
bool mx_isspace(char c);
bool mx_isdigit(int c);
void mx_printerr(const char *s);

#endif
