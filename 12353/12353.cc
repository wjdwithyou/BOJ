#include <iostream>

void addInch(int*, int*, int);

int main() {
	int t, mf, mi, ff, fi, chk;
	char g;

	scanf("%d", &t);

	for (int i = 1; i <= t; ++i) {
		while (getchar() != '\n');

		scanf("%c %d'%d\" %d'%d\"", &g, &mf, &mi, &ff, &fi);

		addInch(&mf, &mi, fi);

		mf += ff;

		addInch(&mf, &mi, (g == 'B') ? 5 : -5);

		chk = mi & 1;

		mi >>= 1;

		if (mf & 1) {
			addInch(&mf, &mi, 6);
		}

		mf >>= 1;

		addInch(&mf, &mi, (chk) ? -3 : -4);
		printf("Case #%d: %d'%d\" ", i, mf, mi);

		addInch(&mf, &mi, (chk) ? 7 : 8);
		printf("to %d'%d\"\n", mf, mi);
	}

	return 0;
}

void addInch(int* mf, int* mi, int dmi) {
	*mi += dmi;

	if (*mi >= 12) {
		*mi -= 12;
		++(*mf);
	}
	else if (*mi < 0) {
		*mi += 12;
		--(*mf);
	}
	else;
	return;
}