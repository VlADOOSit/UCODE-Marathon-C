#include <unistd.h>

int main(int argc, char * argv[]) {
    char sp = '\n';
    for(int i = 1; i < argc; i++) {
        int j = 0;
        for (; argv[i][j] != '\0'; j++) {
        }
        write(1, argv[i], j);    
        write(1, &sp, 1);
    }
    return 0;
}
