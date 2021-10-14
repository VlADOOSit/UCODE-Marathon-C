int mx_factorial_rec(int n) {
    int mult = n;
    if (n == 0) {
        return 1;
    }
    if (n < 0 || n > 12) {
        return 0;
    }
    return mult *= mx_factorial_rec(n - 1);
}
