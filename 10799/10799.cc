#include <iostream>

char buf[131072];
int stack[65536];

int main() {
	int stack_idx = 0;
	int sum = 0;

	scanf("%s", buf);

	for (int i = 0; buf[i] != '\0'; ++i) {
		if (buf[i] == '(') {
			if (buf[i + 1] == ')') {
				stack[stack_idx++] = 1;
				++i;
			}
			else {
				stack[stack_idx++] = 0;
			}
		}
		else {
			int temp = 0;

			for (; stack[stack_idx - 1] != 0; --stack_idx) {
				temp += stack[stack_idx - 1];
			}

			sum += (temp + 1);

			stack[stack_idx - 1] = temp;
		}
	}

	printf("%d", sum);
	return 0;
}