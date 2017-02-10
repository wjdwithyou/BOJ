#include <iostream>
#include <cmath>

int main() {
	int n;
	double _sqrt;

	scanf("%d", &n);

	_sqrt = sqrt(n);

	for (int i = 2; i <= _sqrt; ++i) {
		if (n % i == 0) {
			printf("%d", n - (n / i));
			return 0;
		}
	}

	printf("%d", n - 1);
	return 0;
}