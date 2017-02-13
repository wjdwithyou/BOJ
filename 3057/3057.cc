#include <iostream>

char arr[512][512];

int main() {
	int r, c, hk, inner, outer;

	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; ++i) {
		scanf("%s", arr[i]);
	}

	for (int k = (r < c) ? r : c; k >= 2; --k) {
		hk = (k >> 1) + ((k % 1) ? 1 : 0);

		for (int i = 0; i <= r - k; ++i) {
			for (int j = 0; j <= c - k; ++j) {
				outer = 1;

				for (int ii = 0; ii < hk; ++ii) {
					inner = 0;

					for (int jj = 0; jj < k; ++jj) {
						if (arr[i + ii][j + jj] != arr[i + (k - 1) - ii][j + (k - 1) - jj]) {
							++inner;
							break;
						}
					}

					if (inner) {
						--outer;
						break;
					}
				}

				if (outer) {
					printf("%d", k);
					return 0;
				}
			}
		}
	}

	printf("-1");
	return 0;
}