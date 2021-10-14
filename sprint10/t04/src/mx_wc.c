#include "header.h"

int main(int argc, char *argv[]) { 
    int total_len = argc - 1;
    int total_str = 0;
    int total_char = 0;
    if (argc < 2) {
        int len = 0;
        int str = 0;
        int characters = 0; 
        char temp, helper;
        while (read(0, &temp, 1)) {
            if (mx_isspace(temp) && !mx_isspace(helper)) {
                str++;
                total_str++;
            }
            if (temp == '\n') {
                len++;
                total_len++;
            }
            characters++;
            total_char++;
            helper = temp;
        }
        printall(len, str, characters, 2, argv[0]);
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        int file = open(argv[i], O_RDONLY);
        if (file < 0) {
            mx_printerr("mx_wc: ");
            mx_printerr(argv[i]);
            mx_printerr(": open: ");
            mx_printerr(strerror(errno));
            mx_printerr("\n");
            exit(0);
        }
        char temp, helper;
        if (read(file, &temp, 1) < 0 && errno == EISDIR) {
            mx_printerr("mx_wc: ");
            mx_printerr(argv[i]);
            mx_printerr(": read: ");
            mx_printerr(strerror(errno));
            mx_printerr("\n");
            exit(0);
        }
        if (close(file) < 0){
            exit(0);
        }
        file = open(argv[i], O_RDONLY);
        int len = 1;
        int str = 0;
        int characters = 0; 
        while (read(file, &temp, 1)) {
            if (mx_isspace(temp) && !mx_isspace(helper)) {
                str++;
                total_str++;
            }
            if (temp == '\n') {
                len++;
                total_len++;
            } 
            characters++;
            total_char++;
            helper = temp;
        }
        if (mx_isspace(helper)) {
            len--;
            total_len--;
        }
        if (!mx_isspace(helper)) {
            str++;
            total_str++;
        }
       

        if (close(file) < 0){
            exit(0);
        }
        printall(len, str, characters, 1, argv[i]);
    }
    if (argc <= 2) {
        return 0;
    }
    else {
        printall(total_len, total_str, total_char, 0, argv[0]);
    }
    return 0;
}
