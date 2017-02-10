#include <iostream>

int main() {
	int c;

	scanf("%d", &c);

	for (int i = 0; i < c; ++i) {
		int arr[1024];
		float avg = 0.0f;
		int n;
		int sum = 0;
		int cnt = 0;

		scanf("%d", &n);

		for (int j = 0; j < n; ++j) {
			scanf("%d", &arr[j]);

			sum += arr[j];
		}

		avg = (float)sum / n;

		for (int j = 0; j < n; ++j) {
			if (avg < arr[j]) {
				++cnt;
			}
		}

		printf("%.3f%%\n", 100 * (float)cnt / n);
	}

	return 0;
}