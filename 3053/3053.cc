#include <iostream>
#include <cmath>

int main() {
	const double PI = 2 * asin(1);
	int r;

	scanf("%d", &r);

	r *= r;

	printf("%.6lf\n%.6lf", PI * r, static_cast<double>(2 * r));
	return 0;
}