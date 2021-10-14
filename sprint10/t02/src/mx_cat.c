#include <header.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        int len;
        char buff[1];
        len = read(0, buff, 1);
        while(len) {
            write(1, buff, 1);
            len = read(0, buff, 1);
        }
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY);
        char buff[1];
        int len;

        if (fd < 0) {
            mx_printerr("mx_cp: ");
            mx_printerr(argv[i]);
            mx_printerr(": No such file or directory\n");
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
    }
    return 0;
}
