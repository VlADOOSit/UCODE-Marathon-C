#include "../inc/calculator.h"

#include <stdio.h>
int main (int argc, char *argv[]) {
    if (argc == 1) {
        write(1, "usage: ./calc [operand1] [operation] [operand2]", 47);
        return 0;
    }
    t_operation t;
    enum e_error er;
    bool flag_op = false;
    bool flag_er = false;

    int first_num = mx_atoi(argv[1]);
    int second_num = mx_atoi(argv[3]);
    if (first_num == NOT_NUM || second_num == NOT_NUM) {
        er = INCORRECT_OPERAND;
        flag_er = true;
    }

    if (mx_strncmp(argv[2], "+", 1) == 0) {
        t.op = ADD;
        t.f = mx_add;
        flag_op = true;
    }
    else if (mx_strncmp(argv[2], "-", 1) == 0) {
        t.op = SUB;
        t.f = mx_sub;
        flag_op = true;
    }
    else if (mx_strncmp("*", argv[2], 1) == 0) {
        t.op = MUL;
        t.f = mx_mul;
        flag_op = true;
    }
    else if (mx_strncmp(argv[2], "/", 1) == 0) {
        t.op = DIV;
        t.f = mx_div;
        flag_op = true;
    }
    else if (mx_strncmp(argv[2], "%", 1) == 0) {
        t.op = MOD;
        t.f = mx_mod;
        flag_op = true;
    }
    else {
        er = INCORRECT_OPERATION;
        flag_er = true;
    }
    if (second_num == 0 && (t.op == DIV ||t.op == MOD)) {
        er = DIV_BY_ZERO;
        flag_er = true;
    }
    if (flag_er)
        switch (er) {
            case INCORRECT_OPERAND:
                write(2, "error: invalid number", 21);
                exit(-1);
            case INCORRECT_OPERATION:
                write(2, "error: invalid operation", 24);
                exit(-1);
            case DIV_BY_ZERO:
                write(2, "error: division by zero", 23);
                exit(-1);
        }
    if (flag_op){
        if(t.op == ADD) { 
            mx_printint(t.f(first_num, second_num));
        }
        if(t.op == SUB) {
            mx_printint(t.f(first_num, second_num));
        }
        if(t.op == MUL) { 
            mx_printint(t.f(first_num, second_num));
        }
        if(t.op == DIV) {
            mx_printint(t.f(first_num, second_num));
        }
        if(t.op == MOD){
            mx_printint(t.f(first_num, second_num));
        }
    }
    mx_printchar('\n');
    return 0;
}
