#include "../inc/header.h"

void printall(int len, int str, int characters, int check, char *argv) {
        mx_printchar('\t');
        mx_printint(len);
        mx_printchar('\t');
        mx_printint(str);
        mx_printchar('\t');
        mx_printint(characters);
        if(check == 0){
            mx_printstr("\ttotal\n");
        }
        else if(check == 1) {
            mx_printchar('\t');
            mx_printstr(argv);
            mx_printchar('\n');
        }
        else {
            mx_printchar('\n');
        }
}
