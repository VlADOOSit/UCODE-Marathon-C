double mx_pow_rec(double n, unsigned int pow) {
    int mult = n;
    if (pow == 0) {
        return 1;
    }
    return mult *= mx_pow_rec(n, pow - 1); 
}
