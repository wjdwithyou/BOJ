#include <iostream>

int queue[8192];

int getBiggestIdx(int, int);
void push(int*, int);
int pop(int*);

int main() {
	int t, n, m;
	int front, back;
	int cnt;

	scanf("%d", &t);

	for (int i = 0; i < t; ++i) {
		front = back = 0;
		cnt = 0;

		scanf("%d %d", &n, &m);

		for (int j = 0; j < n; ++j) {
			scanf("%d", &queue[back++]);
		}

		while (true) {
			int temp = getBiggestIdx(front, back);

			for (int j = front; j < temp; ++j) {
				push(&back, pop(&front));

				if (j == m) {
					m = back - 1;
				}
			}

			++cnt;

			if (m == front) {
				printf("%d\n", cnt);
				break;
			}
			else {
				pop(&front);
			}
		}
	}

	return 0;
}

int getBiggestIdx(int front, int back) {
	int max_idx = front;

	for (int i = front + 1; i < back; ++i) {
		if (queue[i] > queue[max_idx]) {
			max_idx = i;
		}
	}

	return max_idx;
}

void push(int* back, int data) {
	queue[(*back)++] = data;
	return;
}

int pop(int* front) {
	return queue[(*front)++];
}