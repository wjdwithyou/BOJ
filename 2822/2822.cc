#include <iostream>

#define MAX_NUM 151
#define NUM 5

int main() {
	int score_arr[MAX_NUM] = { 0, };
	int real_arr[NUM];
	int input, sum, real_arr_idx;

	sum = real_arr_idx = 0;

	for (int i = 1; i <= 8; ++i) {
		scanf("%d", &input);
		score_arr[input] = i;
	}

	for (int i = MAX_NUM - 1; real_arr_idx < NUM; --i) {
		if (score_arr[i]) {
			sum += i;
			real_arr[real_arr_idx++] = score_arr[i];
		}
	}

	for (int i = 0; i < NUM; ++i) {
		int temp;
		int idx = i;

		for (int j = i + 1; j < NUM; ++j) {
			if (real_arr[j] < real_arr[idx]) {
				idx = j;
			}
		}

		temp = real_arr[i];
		real_arr[i] = real_arr[idx];
		real_arr[idx] = temp;
	}

	printf("%d\n", sum);

	for (int i = 0; i < NUM; ++i) {
		printf("%d ", real_arr[i]);
	}

	return 0;
}