#include <iostream>

int getDecimal(char);

int main(void) {
	const char asc[128] = "\0                                !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	char buf[512];
    
	setbuf(stdout, NULL);
    
	while (fgets(buf, 512, stdin)) {
		for (int i = 0; buf[i] != '\n'; i += 2) {
			printf("%c", asc[(getDecimal(buf[i]) << 4) + getDecimal(buf[i + 1])]);
		}
        
		puts("");
	}
    
	return 0;
}

int getDecimal(char c) {
	return c - ((c < 'A') ? '0' : 'A' - 0xa);
}