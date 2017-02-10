#include <iostream>

int main() {
	int t, m, n, x, y, z;

	scanf("%d", &t);

	for (int i = 0; i < t; ++i) {
		bool chk = false;

		scanf("%d %d %d %d", &m, &n, &x, &y);

		z = x - y;

		if (m == n) {
			printf("%d\n", (z) ? -1 : x);
			continue;
		}

		for (int j = 0; j < n; ++j) {
			int temp = m * j + z;

			if (temp % n == 0) {
				printf("%d\n", temp + y);
				chk = true;
				break;
			}
		}

		if (!chk) {
			puts("-1");
		}
	}

	return 0;
}