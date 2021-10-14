int mx_atoi(const char *);
void mx_printchar(char);
void mx_printint(int);

int main(int argc, char *argv[]) {
    int arr[argc - 1];
    for(int i = 1; i < argc; i++) {
        arr[i - 1] = mx_atoi(argv[i]);
    }
    for(int i = 0; i < argc - 1; i++) { 
        int k = arr[i];
        int check = 0;
        if(k < 0) {
            k += 2147483648;
            if(k < 0) {
                k *= -1;
            }
            check =1;
        }
        int temp[32];
        for (int j = 0; j < 32; j++) {
            temp[j] = k % 2;
            k /= 2;
        }
        mx_printint(check);
        for(int j = 30; j >= 0; j--) {
            mx_printint(temp[j]);
        }
        mx_printchar('\n');
    }
}
