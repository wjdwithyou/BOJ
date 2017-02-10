#include <iostream>
#include <cmath>

int main() {
	int t, x, y, z;
	int temp;

	scanf("%d", &t);

	for (int i = 0; i < t; ++i) {
		scanf("%d %d", &x, &y);

		z = y - x;
		temp = static_cast<int>(floor(sqrt(z - 1)));

		if (z <= temp * (temp + 1)) {
			printf("%d\n", 2 * temp);
		}
		else {
			printf("%d\n", 2 * temp + 1);
		}
	}

	return 0;
}