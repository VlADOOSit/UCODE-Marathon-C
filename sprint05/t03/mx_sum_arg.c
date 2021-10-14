int mx_atoi(const char *);
void mx_printchar(char);
void mx_printint(int);

int main(int argc, char* argv[]) {
    int sum = 0;
    for (int i = 1; i < argc; i++) {
        sum += mx_atoi(argv[i]);
    }
    mx_printint(sum);
    mx_printchar('\n');
    return 0;
}
