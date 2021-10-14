#include "part_of_mx.h"

void check_args(char *operand1, char *operator, 
                char *operand2, char *result, int operand1_length, 
                int operator_length, int operand2_length, int result_length);

void equation(int argc, char *operand1, char *operator, char *operand2, char *result) {

    if (mx_strcmp(operator, "?") == 0) {
        equation(argc, operand1, "+", operand2, result);
        equation(argc, operand1, "-", operand2, result);
        equation(argc, operand1, "*", operand2, result);
        equation(argc, operand1, "/", operand2, result);
        return;
    }

    int flag_1_op = 0;
    int flag_2_op = 0;
    int flag_mix_1 = 0;
    int flag_mix_2 = 0;
    int flag_mix_3 = 0;
    int flag_result = 0;
    for (int i = 1; i < argc; i++) {
        for (int j = 0; j <= mx_strlen(operand1); j++) {
            if (operand1[j] == '?') {
                flag_1_op = 1;
                flag_mix_1 = 1;    
            }
            else {
                flag_1_op = 0;
            }
        }
        for (int j = 0; j <= mx_strlen(operand2); j++) {
            if (operand2[j] == '?') {
                flag_2_op = 1;
                flag_mix_2 = 1;    
            }
            else {
                flag_2_op = 0;
            }
        }
        for (int j = 0; j <= mx_strlen(result); j++) {
            if (result[j] == '?') {
                flag_result = 1; 
                flag_mix_3 = 1;   
            }
            else {
                flag_result = 0;
            }
        }
    }
    
    if (flag_1_op == 1) {
        flag_mix_1 = 0;
    }
    if (flag_2_op == 1) {
        flag_mix_2 = 0;
    }
    if (flag_result == 1) {
        flag_mix_3 = 0;
    }

    if (flag_1_op == 1 && flag_2_op == 0 && flag_result == 0 && flag_mix_1 == 0 && flag_mix_2 == 0 && flag_mix_3 == 0 && operand1[0] != '-' && operand2[0] != '-' && result[0] != '-') {
        for (int i = 0; i < mx_pow(10, mx_strlen(operand1)); i++) {
            if (mx_strcmp(operator, "+") == 0) {
                if (i + mx_atoi(operand2) == mx_atoi(result)) 
                    print_result(i, " + ", mx_atoi(operand2), i + mx_atoi(operand2));
            }
            if (mx_strcmp(operator, "-") == 0) {
                if (i - mx_atoi(operand2) == mx_atoi(result))
                    print_result(i, " - ", mx_atoi(operand2), i - mx_atoi(operand2));
            }
            if (mx_strcmp(operator, "*") == 0) {
                if (i * mx_atoi(operand2) == mx_atoi(result)) 
                    print_result(i, " * ", mx_atoi(operand2), i * mx_atoi(operand2));
            }
            if (mx_strcmp(operator, "/") == 0) {
                if (i / mx_atoi(operand2) == mx_atoi(result)) {
                    if (mx_atoi(operand2) == 0) {
                        continue;
                    }
                    print_result(i, " / ", mx_atoi(operand2), i / mx_atoi(operand2));
                }
            }
        }
    }

    if (flag_1_op == 0 && flag_2_op == 1 && flag_result == 0 && flag_mix_1 == 0 && flag_mix_2 == 0 && flag_mix_3 == 0 && operand1[0] != '-' && operand2[0] != '-' && result[0] != '-') {
        for (int i = 0; i < mx_pow(10, mx_strlen(operand2)); i++) {
            if (mx_strcmp(operator, "+") == 0) {
                if (i + mx_atoi(operand1) == mx_atoi(result))
                    print_result(mx_atoi(operand1), " + ", i, i + mx_atoi(operand1));
            }
            if (mx_strcmp(operator, "-") == 0) {
                if (mx_atoi(operand1) - i == mx_atoi(result))
                    print_result(mx_atoi(operand1), " - ", i, mx_atoi(result));
            }
            if (mx_strcmp(operator, "/") == 0) {
                if (i == 0) {
                    continue;
                }
                if (mx_atoi(operand1) / i == mx_atoi(result))
                    print_result(mx_atoi(operand1), " / ", i, mx_atoi(result));
            }
            if (mx_strcmp(operator, "*") == 0) {
                if (mx_atoi(operand1) * i == mx_atoi(result))
                    print_result(mx_atoi(operand1), " * ", i, mx_atoi(result));
            }
        }

    }

    if (flag_1_op == 1 && flag_2_op == 0 && flag_result == 1 && flag_mix_1 == 0 && flag_mix_2 == 0 && flag_mix_3 == 0 && operand1[0] != '-' && operand2[0] != '-' && result[0] != '-')  {
        for (int i = 0; i < mx_pow(10, mx_strlen(operand1)); i++) {
            for (int j = 0; j < mx_pow(10, mx_strlen(result)); j++) {
                if (mx_strcmp(operator, "+") == 0) {
                    if (i + mx_atoi(operand2) == j)
                        print_result(i, " + ", mx_atoi(operand2), j);
                }
                if (mx_strcmp(operator, "-") == 0) {
                    if (i - mx_atoi(operand2) == j)
                        print_result(i, " - ", mx_atoi(operand2), j);
                }
                if (mx_strcmp(operator, "*") == 0) {
                    if (i * mx_atoi(operand2) == j)
                        print_result(i, "* ", mx_atoi(operand2), j);
                }
                if (mx_strcmp(operator, "/") == 0) {
                    if (mx_atoi(operand2) == 0) {
                        continue;
                    }
                    if (i / mx_atoi(operand2) == j) 
                        print_result(i, " / ", mx_atoi(operand2), j);
                }
            }
        }
    }

    if (flag_1_op == 1 && flag_2_op == 1 && flag_result == 0 && flag_mix_1 == 0 && flag_mix_2 == 0 && flag_mix_3 == 0 && operand1[0] != '-' && operand2[0] != '-' && result[0] != '-') {
        for (int i = 0; i < mx_pow(10, mx_strlen(operand1)); i++) {
            for (int j = 0; j < mx_pow(10, mx_strlen(operand2)); j++) {
                if (mx_strcmp(operator, "+") == 0) {
                    if (i + j == mx_atoi(result))
                        print_result(i, " + ", j, mx_atoi(result));
                }
                if (mx_strcmp(operator, "-") == 0) {
                    if (i - j == mx_atoi(result)) 
                        print_result(i, " - ", j, mx_atoi(result));
                }
                if (mx_strcmp(operator, "*") == 0) {
                    if (i * j == mx_atoi(result))
                        print_result(i, " * ", j, mx_atoi(result));
                }
                if (mx_strcmp(operator, "/") == 0) {
                    if (j == 0) {
                        continue;
                    }
                    if (i / j == mx_atoi(result))
                        print_result(i, " / ", j, mx_atoi(result));
                }
            }
        }
    }

    if (flag_1_op == 0 && flag_2_op == 0 && flag_result == 1 && flag_mix_1 == 0 && flag_mix_2 == 0 && flag_mix_3 == 0 && operand1[0] != '-' && operand2[0] != '-' && result[0] != '-') {
        for (int i = 0; i < mx_pow(10, mx_strlen(result)); i++) {
            if (mx_strcmp(operator, "+") == 0) {
                if (mx_atoi(operand1) + mx_atoi(operand2) == i)
                    print_result(mx_atoi(operand1), " + ", mx_atoi(operand2), i);
            }
            if (mx_strcmp(operator, "-") == 0) {
                if (mx_atoi(operand1) - mx_atoi(operand2) == i)
                    print_result(mx_atoi(operand1), " - ", mx_atoi(operand2), i);
            }
            if (mx_strcmp(operator, "*") == 0) {
                if (mx_atoi(operand1) * mx_atoi(operand2) == i)
                    print_result(mx_atoi(operand1), " * ", mx_atoi(operand2), i);
            }
            if (mx_strcmp(operator, "/") == 0) {
                if (mx_atoi(operand2) == 0) {
                        continue;
                    }
                if (mx_atoi(operand1) / mx_atoi(operand2) == i)
                    print_result(mx_atoi(operand1), " / ", mx_atoi(operand2), i);
            }
        }
    }
    if (flag_1_op == 0 && flag_2_op == 1 && flag_result == 1 && flag_mix_1 == 0 && flag_mix_2 == 0 && flag_mix_3 == 0 && operand1[0] != '-' && operand2[0] != '-' && result[0] != '-') {
        for (int i = 0; i < mx_pow(10, mx_strlen(operand2)); i++) {
            for (int j = 0; j < mx_pow(10, mx_strlen(result)); j++) {
                if (mx_strcmp(operator, "+") == 0) {
                    if (mx_atoi(operand1) + i == j)
                        print_result(mx_atoi(operand1), " + ", i, j);
                }
                if (mx_strcmp(operator, "-") == 0) {
                    if (mx_atoi(operand1) - i == j)
                        print_result(mx_atoi(operand1), " - ", i, j);
                }
                if (mx_strcmp(operator, "*") == 0) {
                    if (mx_atoi(operand1) * i == j)
                        print_result(mx_atoi(operand1), " * ", i, j);
                }
                if (mx_strcmp(operator, "/") == 0) {
                    if (i == 0) {
                        continue;
                    }
                    if (mx_atoi(operand1) / i == j)
                        print_result(mx_atoi(operand1), " / ", i, j);
                }
            }
        }
    }

    if (flag_1_op == 1 && flag_2_op == 1 && flag_result == 1 && flag_mix_1 == 0 && flag_mix_2 == 0 && flag_mix_3 == 0 && operand1[0] != '-' && operand2[0] != '-' && result[0] != '-') {
        for (int i = 0; i < mx_pow(10, mx_strlen(operand1)); i++) {
            for (int j = 0; j < mx_pow(10, mx_strlen(operand2)); j++) {
                for (int k = 0; k < mx_pow(10, mx_strlen(result)); k++) {
                    if (mx_strcmp(operator, "+") == 0) {
                        if (i + j == k)
                            print_result(i, " + ", j, k);
                    }
                    if (mx_strcmp(operator, "-") == 0) {
                        if (i - j == k)
                            print_result(i, " - ", j, k);
                    }
                    if (mx_strcmp(operator, "*") == 0) {
                        if (i * j == k)
                            print_result(i, " * ", j, k);
                    }
                    if (mx_strcmp(operator, "/") == 0) {
                        if (j == 0) {
                            continue;
                        }
                        if (i / j == k)
                            print_result(i, " / ", j, k);
                    }
                }
            }
        }
    }
    if (flag_1_op == 0 && flag_2_op == 0 && flag_result == 0 && flag_mix_1 == 0 && flag_mix_2 == 0 && flag_mix_3 == 0 && operand1[0] != '-' && operand2[0] != '-' && result[0] != '-') {
        if (mx_strcmp(operator, "+") == 0) {
            if (mx_atoi(operand1) + mx_atoi(operand2) == mx_atoi(result))
                print_result(mx_atoi(operand1), " + ", mx_atoi(operand2), mx_atoi(result));
        }   
        if (mx_strcmp(operator, "-") == 0) {
            if (mx_atoi(operand1) - mx_atoi(operand2) == mx_atoi(result))
                print_result(mx_atoi(operand1), " - ", mx_atoi(operand2), mx_atoi(result));
        }   
        if (mx_strcmp(operator, "*") == 0) {
            if (mx_atoi(operand1) * mx_atoi(operand2) == mx_atoi(result))
                print_result(mx_atoi(operand1), " * ", mx_atoi(operand2), mx_atoi(result));
        }   
        if (mx_strcmp(operator, "/") == 0 && mx_atoi(operand2)!=0) {
            if (mx_atoi(operand1) / mx_atoi(operand2) == mx_atoi(result))
                print_result(mx_atoi(operand1), " / ", mx_atoi(operand2), mx_atoi(result));
        }   
    }

    int len_1 = mx_strlen(operand1);
    int len_2 = mx_strlen(operand2);
    int len_res = mx_strlen(result);
    bool flag_neg_1 = false;
    bool flag_neg_2 = false;
    bool flag_res_neg = false;

    if (flag_mix_1 == 1 || flag_mix_2 == 1 || flag_mix_3 == 1 || operand1[0] == '-' || operand2[0] == '-' || result[0] == '-') {
        if (operand1[0] == '-') {
            operand1++;
            len_1--;
            flag_neg_1 = true;
        } 
        if (operand2[0] == '-') {
            operand2++;
            len_2--;
            flag_neg_2 = true;
        }
        if (result[0] == '-') {
            result++;
            len_res--;
            flag_res_neg = true;
        }
        for (int i = 0; i < mx_pow(10, len_1); i++) {
            bool check_i = true;
            char *str_i = mx_itoa(i);
            int i_len = mx_strlen(str_i);
            for (int j = len_1 - i_len, counter_i = 0; j < len_1; j++, counter_i++) {
                if (operand1[j] != '?' && operand1[j] != str_i[counter_i]) {
                    check_i = false;
                    break;
                }
            }
            if(check_i) {
                for (int j = 0; j < len_1 - i_len; j++) {
                    if (mx_isdigit(operand1[j]) && operand1[j] != '0') {
                        check_i = false;
                        break;
                    }
                }
            }
            free(str_i); 
            str_i = NULL;
            if (!check_i) {
                continue;
            }
            for (int j = 0; j < mx_pow(10, len_2); j++) { 
                bool check_j = true;
                char *str_j = mx_itoa(j);
                int j_len = mx_strlen(str_j);
                for (int n = len_2 - j_len, counter_j = 0; n < len_2; n++, counter_j++) {
                    if (operand2[n] != '?' && operand2[n] != str_j[counter_j]) {
                        check_j = false;
                        break;
                    }
                }
                if(check_j) {
                    for (int k = 0; k < len_2 - j_len; k++) {
                        if (mx_isdigit(operand2[k]) && operand2[k] != '0') {
                            check_j = false;
                            break;
                        }
                    }
                }
                free(str_j); 
                str_j = NULL;
                if (!check_j)
                    continue;
                for (int k = 0; k < mx_pow(10, len_res); k++) {
                    bool check_k = true;
                    char *str_k = mx_itoa(k);
                    int k_len = mx_strlen(str_k);
                    for (int p = len_res - k_len, counter_n = 0; p < len_res; p++, counter_n++) {
                        if (result[p] != '?' && result[p] != str_k[counter_n]) {
                            check_k = false;
                            break;
                        }
                    }
                    if(check_k) {
                        for (int p = 0; p < len_res - k_len; p++) {
                            if (mx_isdigit(result[p]) && result[p] != '0') {
                                check_k = false;
                                break;
                            }
                        }
                    }
                    free(str_k); 
                    str_k = NULL;
                    if (!check_k) {
                        continue;
                    }
                    if (flag_neg_1) {
                        i *= -1;
                    }
                    if (flag_neg_2) {
                        j *= -1;
                    }
                    if (flag_res_neg) {
                        k *= -1;
                    }
                    if (*operator == '+') {
                        if (i + j == k)
                            print_result(i, " + ", j, k);
                    }
                    else if (*operator == '-') {
                        if (i - j == k)
                            print_result(i, " - ", j, k);
                    }
                    else if (*operator == '*') {
                        if (i * j == k)
                            print_result(i, " * ", j, k);
                    }
                    else if (*operator == '/') {
                        if (j != 0 && i / j == k)
                            print_result(i, " / ", j, k);
                    }
                    if (flag_neg_1) {
                        i *= -1;
                    }
                    if (flag_neg_2) {
                        j *= -1;
                    }
                    if (flag_res_neg) {
                        k *= -1;
                    }
                }
            }
        }
        if (flag_neg_1) {
            operand1--;
        }
        if (flag_neg_2) {
            operand2--;
        }
        if (flag_res_neg) {
            result--;
        }
    }
}
