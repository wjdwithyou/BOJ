#include <iostream>

#define MAX_NUM 4000

int counter[2 * MAX_NUM + 1];

void findMedianAndMode(int, int*, int*);

int main() {
	int n, t;
	int average, median, mode, range;
	int min = MAX_NUM;
	int max = -MAX_NUM;
	int sum = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);

		sum += t;
		++counter[t + MAX_NUM];

		if (t < min) {
			min = t;
		}

		if (t > max) {
			max = t;
		}
	}

	double raw_avg = sum / static_cast<double>(n);
	raw_avg += (raw_avg >= 0) ? 0.5 : -0.5;

	average = static_cast<int>(raw_avg);
	range = max - min;

	findMedianAndMode(n, &median, &mode);

	printf("%d\n%d\n%d\n%d", average, median, mode, range);
	return 0;
}

void findMedianAndMode(int n, int* median, int* mode) {
	int mode_arr[2 * MAX_NUM + 1];
	int mode_arr_idx = 0;
	int max = -1;

	int half = (n + 1) / 2;
	int sum = 0;
	bool chk = false;

	for (int i = 0; i < 2 * MAX_NUM + 1; ++i) {
		if (!chk) {
			sum += counter[i];

			if (sum >= half) {
				*median = i - MAX_NUM;
				chk = true;
			}
		}

		if (counter[i] > max) {
			mode_arr_idx = 0;
			mode_arr[mode_arr_idx++] = i;
			max = counter[i];
		}
		else if (counter[i] == max) {
			mode_arr[mode_arr_idx++] = i;
		}
		else;
	}

	if (mode_arr_idx == 1) {
		*mode = mode_arr[0] - MAX_NUM;
	}
	else {
		int min1, min2;

		min1 = min2 = 524288;

		for (int i = 0; i < mode_arr_idx; ++i) {
			if (mode_arr[i] < min1) {
				min2 = min1;
				min1 = mode_arr[i];
			}
			else if (mode_arr[i] < min2) {
				min2 = mode_arr[i];
			}
			else;
		}

		*mode = min2 - MAX_NUM;
	}

	return;
}