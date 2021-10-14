#include <unistd.h>

void mx_printint(int n) {
    int dop = 48;
    if (n == 0) {
        dop = 48;
        write(1, &dop, 1);
        return;
    }
    if (n < 0) {
        dop = 45;
        write(1, &dop, 1);
        n *= -1;
    }
    int temp = n;
    int counter = 0;
    while(temp != 0) {
        temp = temp / 10;
        counter++;
    }
    int array[counter];
    int count_mass = 0;
    while(n != 0) { 
        array[count_mass] = n % 10;
        n /= 10;
        count_mass++;
    }
    for(int j = count_mass - 1; j >= 0; j--) {
        dop = array[j] + 48;
        write(1, &dop, 1);;
    }
}

int main(int argc, char * argv[]) {
    int i = 0;
    char nl = '\n';
    for (; argv[0][i] != '\0'; i++) {

    }
    write(1, argv[0], i);
    write(1, &nl, 1);
    mx_printint(argc);
    write(1, &nl, 1);
    return 0;
}
