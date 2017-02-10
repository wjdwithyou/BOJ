#include <iostream>

#define MAX_SIZE 1024

int queue[MAX_SIZE];

void push(int*, int);
int pop(int*);

int main() {
	int n, m;
	int front, back;

	front = back = 0;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		push(&back, i);
	}

	printf("<");
	for (int i = 1; front != back; ++i) {
		if (i % m == 0) {
			if (i == m) {
				printf("%d", pop(&front));
			}
			else {
				printf(", %d", pop(&front));
			}
		}
		else {
			push(&back, pop(&front));
		}
	}
	printf(">");
	return 0;
}

void push(int* back, int data) {
	queue[(*back)++ % MAX_SIZE] = data;
	return;
}

int pop(int* front) {
	return queue[(*front)++ % MAX_SIZE];
}