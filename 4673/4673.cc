#include <iostream>

int d(int);
void r(int[], int);

int d(int);
void r(int[], int);

int main() {
	int arr[10001] = { 0, };

	for (int i = 1; i <= 10000; ++i) {
		if (arr[i] == 0) {
			printf("%d\n", i);

			r(arr, i);
		}
	}

	return 0;
}

void r(int arr[], int n) {
	int t = d(n);

	if (t > 10000)
		return;

	arr[t] = 1;
	r(arr, t);

	return;
}

int d(int n) {
	int q4 = n / 10000;
	int r4 = n % 10000;
	int q3 = r4 / 1000;
	int r3 = r4 % 1000;
	int q2 = r3 / 100;
	int r2 = r3 % 100;
	int q1 = r2 / 10;
	int r1 = r2 % 10;

	return n + q4 + q3 + q2 + q1 + r1;
}