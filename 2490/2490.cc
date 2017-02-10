#include <iostream>

int main() {
	int t, cnt;

	for (int i = 0; i < 3; ++i) {
		cnt = 0;

		for (int j = 0; j < 4; ++j) {
			scanf("%d", &t);

			if (!t) {
				++cnt;
			}
		}

		if (!cnt) {
			cnt += 5;
		}

		printf("%c\n", 'A' + --cnt);
	}

	return 0;
}