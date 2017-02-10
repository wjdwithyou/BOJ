#include <iostream>

int main() {
	int a, b, c;

	scanf("%d %d", &a, &b);

	if (a < b) {
		a ^= b ^= a ^= b;
	}

	c = a * b;

	while (true) {
		int temp = a % b;

		if (temp == 0) {
			printf("%d\n%d", b, c / b);
			break;
		}
		else {
			a = b;
			b = temp;
		}
	}

	return 0;
}