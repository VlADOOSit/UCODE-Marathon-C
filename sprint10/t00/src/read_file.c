#include "header.h"

int main(int argc, char *argv[]) {
    char buff[1];
    int fd;
    int len;

    if(argc != 2) {
        mx_printerr("usage: ./read_file [file_path]\n");
        exit(0);
    }

    fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        mx_printerr("error\n");
        exit(0);
    }

     
    len = read(fd, buff, 1);

    while(len) {
        write(1, buff, 1);
        len = read(fd, buff, 1);
    }

    if(close(fd) == -1) {
        mx_printerr("error\n");
        exit(0);
    }
    
    return 0;
}
