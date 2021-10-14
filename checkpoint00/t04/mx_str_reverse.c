void mx_str_reverse(char *s) {
    int counter = 0;
    while(s[counter] != '\0') {
        counter++;
    }
    int i = 0;
    while(i != counter / 2) {
        char temp = s[i];
        s[i] = s[counter - 1 - i];
        s[counter - 1 - i] = temp;
        i++;
    }
}
