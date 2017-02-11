#include <iostream>

void ii(int[], int);
void ss(int[], int, char);

int main() {
	int a[64], b[64];
	int n;
	int s = 0;

	scanf("%d", &n);

	ii(a, n);
	ss(a, n, 'a');

	ii(b, n);
	ss(b, n, 'b');

	for (int i = 0; i < n; ++i) {
		s += (a[i] * b[i]);
	}

	printf("%d", s);
	return 0;
}

void ii(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
}

void ss(int arr[], int n, char sort) {
	int idx, temp;

	for (int i = 0; i < n; ++i) {
		idx = i;

		for (int j = i + 1; j < n; ++j) {
			if (sort == 'a') {
				if (arr[idx] > arr[j]) {
					idx = j;
				}
			}
			else {
				if (arr[idx] < arr[j]) {
					idx = j;
				}
			}
		}

		temp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = temp;
	}

	return;
}