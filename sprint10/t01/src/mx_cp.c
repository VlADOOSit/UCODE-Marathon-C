#include "header.h"

int main(int argc, char *argv[]) {
    int fd1;
    int fd2;
    char buff[1];
    int len;
    
    if (argc != 3) {
        mx_printerr("usage: ./mx_cp [source_file] [destination_file]\n");
        exit(0);
    }
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_CREAT | O_EXCL | O_WRONLY, 00400 | 00200);
    
    if (fd1 < 0) {
        mx_printerr("mx_cp: ");
        mx_printerr(argv[1]);
        mx_printerr(": No such file or directory\n");
        exit(0);
    }

    len = read(fd1, buff, 1);
    while(len) {
        write(fd2, buff, 1);
        len = read(fd1, buff, 1);
    }

    if(close(fd1) < 0) {
        mx_printerr("error\n");
        exit(0);
    }
    if(close(fd2) < 0) {
        mx_printerr("error\n");
        exit(0);
    }
    return 0;
}
