#include <iostream>

int arr[1024][1024] = { 0, };

int main() {
	int n, k;

	arr[1][0] = arr[1][1] = 1;

	for (int i = 2; i <= 1000; ++i) {
		for (int j = 0; j <= i; ++j) {
			arr[i][j] = (j == 0) ? 1 : (arr[i - 1][j - 1] + arr[i - 1][j]) % 10007;
		}
	}

	scanf("%d %d", &n, &k);
	printf("%d", arr[n][k]);

	return 0;
}