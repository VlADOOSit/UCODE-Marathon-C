#include "part_of_mx.h"

void check_args(char *operand1, char *operation, 
                char *operand2, char *result, int operand1_length, 
                int operation_length, int operand2_length, int result_length) {
  
    // checking operation
    if (operation_length != 1) {
        mx_printerr(I_OPERATION);
        mx_printerr(operation);
        mx_printerr("\n");
        exit(-1);
    }
    if (operation_length != 1 && *operation != '?' && *operation != '+' && 
        *operation != '-' && *operation != '*' && *operation != '/') {
        mx_printerr(I_OPERATION);
        mx_printerr(operation);
        mx_printerr("\n");
        exit(-1);
    }
    
    // checking operands
    if (operand1_length <= 0) {
        mx_printerr(I_OPERAND);
        mx_printerr(operand1);
        mx_printerr("\n");
        exit(-1);
    }
    else if (operand2_length <= 0) {
        mx_printerr(I_OPERAND);
        mx_printerr(operand2);
        mx_printerr("\n");
        exit(-1);
    }
    for (int i = 0; i < operand1_length; i++) {
        if (operand1[i] == '-' && i == 0) {
            if (!mx_isdigit(operand1[i + 1]) && operand1[i + 1] != '?') {
                mx_printerr(I_OPERAND);
                mx_printerr(operand1);
                mx_printerr("\n");
                exit(-1);
            }
            continue;
        }
        if (!mx_isdigit(operand1[i]) && operand1[i] != '?') {
            mx_printerr(I_OPERAND);
            mx_printerr(operand1);
            mx_printerr("\n");
            exit(-1);
        }
    }
    for (int i = 0; i < operand2_length; i++) {
        if (operand2[i] == '-' && i == 0) {
            if (!mx_isdigit(operand2[i + 1]) && operand2[i + 1] != '?') {
                mx_printerr(I_OPERAND);
                mx_printerr(operand2);
                mx_printerr("\n");
                exit(-1);
            }
            continue;
        }
        if (!mx_isdigit(operand2[i]) && operand2[i] != '?') {
            mx_printerr(I_OPERAND);
            mx_printerr(operand2);
            mx_printerr("\n");
            exit(-1);
        }
    }

    // checking result
    if (result_length <= 0) {
        mx_printerr(I_RESULT);
        mx_printerr(result);
        mx_printerr("\n");
    }
    for (int i = 0; i < result_length; i++) {
        if (result[i] == '-' && i == 0) {
            if (!mx_isdigit(result[i + 1]) && result[i + 1] != '?') {
                mx_printerr(I_RESULT);
                mx_printerr(result);
                mx_printerr("\n");
                exit(-1);
            }
            continue;
        }
        if (result[i] != '?' && !mx_isdigit(result[i])) {
            mx_printerr(I_RESULT);
            mx_printerr(result);
            mx_printerr("\n");
            exit(-1);
        }
    } 
}
