#include <iostream>

#define BUF_SIZE 1048576

int buf[BUF_SIZE];
int temp[BUF_SIZE];

void devide(int, int);
void merge(int, int, int);

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &buf[i]);
	}

	devide(0, n - 1);

	for (int i = 0; i < n; ++i) {
		printf("%d\n", buf[i]);
	}

	return 0;
}

void devide(int a, int b) {
	if (a == b) {
		return;
	}

	int m = (a + b) / 2;

	devide(a, m);
	devide(m + 1, b);
	merge(a, m + 1, b);

	return;
}

void merge(int a, int m, int b) {
	int _a = a;
	int _m = m;
	int _b = b;

	for (int i = a; i <= b; ++i) {
		if (_a == m) {
			temp[i] = buf[_m++];
		}
		else if (_m == b + 1) {
			temp[i] = buf[_a++];
		}
		else {
			temp[i] = (buf[_a] < buf[_m]) ? buf[_a++] : buf[_m++];
		}
	}

	for (int i = a; i <= b; ++i) {
		buf[i] = temp[i];
	}

	return;
}