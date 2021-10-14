void mx_printchar(char);

void mx_isos_triangle(unsigned int length, char c) {
    for (int i = 0; i < length; i++) {
		for (int j = 0; j <= i; j++){
			printchar(c);
		}
		printchar('\n');
	}
}
