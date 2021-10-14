#include "part_of_mx.h"


int main(int argc, char *argv[]) {
    if (argc != 5) {
        mx_printerr(I_USAGE);
        mx_printerr("\n");
        exit(-1);
    }
    
    char *operand1 = mx_strtrim(argv[1]);
    char *operand2 = mx_strtrim(argv[3]);
    char *operator = mx_strtrim(argv[2]);
    char *result = mx_strtrim(argv[4]);
    
    check_args(operand1, operator, operand2, result, mx_strlen(operand1), mx_strlen(operator), mx_strlen(operand2), mx_strlen(result));

    equation(argc, operand1, operator, operand2, result);

    free(operand1);
    operand1 = NULL;
    free(operator);
    operator = NULL;
    free(operand2);
    operand2 = NULL;
    free(result);
    result = NULL;

    return 0;
}
