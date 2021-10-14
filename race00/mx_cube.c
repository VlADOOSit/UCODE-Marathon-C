void mx_printchar(char);

void mx_cube(int n) {
    if( n <= 1) {
        return;
    }
    for(int i = 0; i < n/2 + 1; i++) {
        mx_printchar(' ');
    }
    mx_printchar('+');
    for(int i = 0; i < 2*n; i++) {
        mx_printchar('-');
    }
    mx_printchar('+');
    mx_printchar('\n');
    for(int i = 0; i <= (n - 2) / 2; i++) {
        for(int j = 0; j <= n * 2 + n / 2 + 1; j++) {
            if(j == n / 2 - i || j == n * 2  + n / 2  + 1 - i ){
                mx_printchar('/');
            }
            else {
                mx_printchar(' ');
            }
            if( j == n * 2 + n / 2 + 1){
                mx_printchar('|');
            }
        }
        mx_printchar('\n');
    }
    mx_printchar('+');
    for(int i = 0; i < 2*n; i++) {
        mx_printchar('-');
    }
    mx_printchar('+');
    int check = 1;
    for(int i = 0; i < n; i++){
        if(i == 0) {
            for(int j = 0; j <= n/2; j++) {
                if(j == n/2) {
                    mx_printchar('|');
                }
                else {
                    mx_printchar(' ');
                }
            }
            mx_printchar('\n');
        }
        mx_printchar('|');
        for(int j = 0; j < 2*n; j++) {
            mx_printchar(' ');
        }
        mx_printchar('|');
        for(int j = 0; j < n/2; j++) {
            if(j == n/2 - check && i > n/2 && n % 2 == 1) {
                mx_printchar('/');
                check ++;
            }
            else if(j == n/2 - check && i > n/2 - 1 && n % 2 == 0)
            {
                mx_printchar('/');
                check ++;
            }
            else {
            mx_printchar(' ');
            }
        }
        if(i < n/2 - 1 && n % 2 == 0) {
            mx_printchar('|');
        }
        else if(i < n/2 && n % 2 == 1) {
            mx_printchar('|');
        }
        if(i == n - n/2 - 1) {
            mx_printchar('+');
        }
        mx_printchar('\n');
    }
    mx_printchar('+');
    for(int i = 0; i < 2*n; i++) {
        mx_printchar('-');
    }
    mx_printchar('+');
    mx_printchar('\n');
}

int main() {
    mx_cube(50);
    return 0;
}
