#include <iostream>
#include <cstring>

int main() {
	char buf[8];
	int n, limit, tsum;
	int r = 0;

	scanf("%s", buf);

	n = atoi(buf);
	limit = n - (9 * strlen(buf));

	for (int i = limit; i < n; ++i) {
		sprintf(buf, "%d", i);

		tsum = i;

		for (int j = 0; buf[j] != '\0'; ++j) {
			tsum += (buf[j] - '0');
		}

		if (tsum == n) {
			r = i;
			break;
		}
	}

	printf("%d", r);
	return 0;
}