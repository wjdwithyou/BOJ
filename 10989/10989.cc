#include <iostream>

int counter[10001] = { 0, };

int main() {
	int n, t;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);

		++counter[t];
	}

	for (int j = 1; j < 10001; ++j) {
		for (int k = 0; k < counter[j]; ++k) {
			printf("%d\n", j);
		}
	}

	return 0;
}