#include <iostream>

int getDigiRoot(int);

int main() {
	char buf[1024];
    int sum;

	while (true) {
        sum = 0;
        
		scanf("%s", buf);

		if (buf[0] == '0') {
			break;
		}

		for (int i = 0; buf[i] != '\0'; ++i) {
			sum += (buf[i] - '0');
		}

		printf("%d\n", getDigiRoot(sum));
	}

	return 0;
}

int getDigiRoot(int n) {
	if (n < 10) {
		return n;
	}

	int sum = 0;

	for (int i = 1000; i > 1; i /= 10) {
		sum += (n / i);
		n %= i;
	}

	sum += n;

	return getDigiRoot(sum);
}