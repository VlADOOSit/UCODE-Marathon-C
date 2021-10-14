#ifndef PARTOFMX_H
#define PARTOFMX_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define I_OPERATION "Invalid operation: "
#define I_OPERAND "Invalid operand: "
#define I_RESULT "Invalid result: "
#define I_USAGE "usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]"

char *mx_itoa(long long number);
int mx_atoi(const char* str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
char *mx_strnew(const int size);
void mx_printchar(char c);
char *mx_strtrim(const char *str); 
void mx_printint(int n);
void mx_printstr(const char *s);
void mx_printerr(const char *s);
int mx_strlen(const char *s);
double mx_pow(double n, unsigned int pow);
int mx_strcmp (const char *s1, const char *s2);

void check_args(char *operand1, char *operation, char *operand2, 
                char *result, int operand1_length, int operation_length, 
                int operand2_length, int result_length);
void print_result(int operand1, char *operator, int operand2, int result);
void equation(int argc, char *operand1, char *operator, char *operand2, char *result);
#endif
