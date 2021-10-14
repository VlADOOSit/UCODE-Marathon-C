int mx_factorial_iter(int n) {
    int mult = 1;
    if (n < 0 || n > 12) {
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        mult *= i;
    }
    return mult;
}
