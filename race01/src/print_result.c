#include "part_of_mx.h"

void print_result(int operand1, char *operator, int operand2, int result) {
    mx_printint(operand1);
    mx_printstr(operator);
    mx_printint(operand2);
    mx_printstr(" = ");
    mx_printint(result);
    mx_printchar('\n');
}
