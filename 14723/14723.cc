#include <iostream>

int main(void) {
	int n, d;

	scanf("%d", &n);

	for (int i = 1;; ++i) {
		d = ((i * (i + 1)) >> 1) - n;

		if (d >= 0) {
			printf("%d %d", 1 + d, i - d);
			break;
		}
	}

	return 0;
}