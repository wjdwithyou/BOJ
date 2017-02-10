#include <iostream>

#define BUF_SIZE 1048576

char buf[BUF_SIZE];

int main() {
	int cnt = 1;
	bool chk = false;

	fgets(buf, BUF_SIZE, stdin);

	for (int i = 0; (buf[i] != '\0' && buf[i] != '\n'); ++i) {
		if (buf[i] == ' ') {
			if (chk) {
				++cnt;
				chk = false;
			}
		}
		else {
			if (!chk) {
				chk = true;
			}
		}

	}

	if (!chk) {
		--cnt;
	}

	printf("%d", cnt);
	return 0;
}