#include <iostream>

int main() {
	int x;
	int sum = 0;

	scanf("%d", &x);

	for (; x != 0; x >>= 1) {
		sum += (x & 1);
	}

	printf("%d", sum);
	return 0;
}