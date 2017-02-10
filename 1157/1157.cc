#include <iostream>

char buf[1048576];

int main() {
	int counter[26] = { 0, };

	scanf("%s", buf);

	for (int i = 0; buf[i] != '\0'; ++i) {
		int idx = (buf[i] >= 'a') ? buf[i] - 'a' : buf[i] - 'A';

		++counter[idx];
	}

	int aidx;
	int amax = -1;

	for (int i = 0; i < 26; ++i) {
		if (counter[i] > amax) {
			aidx = i;
			amax = counter[i];
		}
	}

	counter[aidx] = -1;

	int bidx;
	int bmax = -1;
	
	for (int i = 0; i < 26; ++i) {
		if (counter[i] > bmax) {
			bidx = i;
			bmax = counter[i];
		}
	}

	if (amax == bmax) {
		printf("?");
	}
	else {
		printf("%c", aidx + 'A');
	}

	return 0;
}