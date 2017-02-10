#include <iostream>

int main() {
	int t, h, w, n;

	scanf("%d", &t);

	for (int i = 0; i < t; ++i) {
		int a, b;

		scanf("%d %d %d", &h, &w, &n);

		b = (n / h) + 1;
		a = n % h;

		if (n % h == 0) {
			a = h;
			--b;
		}

		printf("%d\n", 100 * a + b);
	}

	return 0;
}