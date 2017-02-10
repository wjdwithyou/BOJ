#include <iostream>

int main() {
	int dMax[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char day[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	int month, date;
	int counter = 0;

	scanf("%d %d", &month, &date);

	for (int i = 1; i < month; ++i) {
		counter += (dMax[i - 1] % 7);
	}

	counter += ((date % 7) - 1);

	counter %= 7;

	printf("%s", day[counter]);

	return 0;
}