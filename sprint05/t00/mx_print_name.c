void mx_printint(int);
void mx_printstr(const char *);
void mx_printchar(char);

int main(int argc, char * argv[]) {
    mx_printstr(argv[0]);
    mx_printchar('\n');
    mx_printint(argc);
    mx_printchar('\n');
    return 0;
}
