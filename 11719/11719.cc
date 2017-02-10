#include <iostream>

#define BUF_SIZE 128

int main() {
	char buf[BUF_SIZE];

	while (fgets(buf, BUF_SIZE, stdin)) {
		printf("%s", buf);
	}

	return 0;
}