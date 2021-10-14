void mx_printchar(char);

void mx_pyramid(int n) {
    int t_front_piramid;
    int t_top_piramid = 1;
    int t_base_piramid = 1;
    if (n % 2 != 0 || n <= 1) {
        return;
    }
    for (int i = n; i > 0; i--) {
        t_front_piramid = i;
        while (t_front_piramid - 1 > 0) {
            mx_printchar(' ');
            t_front_piramid--;
        }
        mx_printchar('/');
        if (i == n) {
           mx_printchar('\\'); 
        }
        if (i <= n - 1 && i > n/2 && i > 1) {
            for (int j = 0; j < t_top_piramid; j++) {
                mx_printchar(' ');
            }
            mx_printchar('\\');
            for (int j = 0; j < t_base_piramid; j++) {
                mx_printchar(' ');
            }
            mx_printchar('\\');
            t_top_piramid += 2;
            t_base_piramid++;
        }
        if (i <= n/2 && i > 1) {
            for (int j = 0; j < t_top_piramid; j++) {
                mx_printchar(' ');
            }
            mx_printchar('\\');
            for (int j = t_base_piramid - 1; j > 0; j--) {
                mx_printchar(' ');
            }
            mx_printchar('|');
            t_top_piramid += 2;
            t_base_piramid--;
        }
       if (i == 1) {
           for (int j = 0 ; j < t_top_piramid; j++) {
                mx_printchar('_');
            }
            mx_printchar('\\');
            mx_printchar('|');
        }
        mx_printchar('\n');
    }
}


