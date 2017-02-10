#include <iostream>

void push(int[], int*, int);
int pop(int[], int*);
int top(int[], int);
bool is_empty(int);

int main() {
	int stack[32];
	char buf[32];
	int stack_idx = 0;

	scanf("%s", buf);

	for (int i = 0; buf[i] != '\0'; ++i) {
		int d = (buf[i] == '(' || buf[i] == ')') ? -2 : -3;

		switch (buf[i]) {
		case '(':
		case '[':
			push(stack, &stack_idx, d);
			break;
		case ')':
		case ']':
			if (is_empty(stack_idx)) {
				printf("0");
				return 0;
			}

			if (top(stack, stack_idx) == d) {
				int temp = pop(stack, &stack_idx) * -1;

				if (!is_empty(stack_idx) && top(stack, stack_idx) > 0) {
					temp += pop(stack, &stack_idx);
				}

				push(stack, &stack_idx, temp);
			}
			else if (top(stack, stack_idx) > 0) {
				int temp = pop(stack, &stack_idx);

				if (is_empty(stack_idx) || top(stack, stack_idx) != d) {
					printf("0");
					return 0;
				}

				if (top(stack, stack_idx) == d) {
					temp *= (pop(stack, &stack_idx) * -1);

					if (!is_empty(stack_idx) && top(stack, stack_idx) > 0) {
						temp += pop(stack, &stack_idx);
					}

					push(stack, &stack_idx, temp);
				}
			}
			else {
				printf("0");
				return 0;
			}
			break;
		default:
			break;
		}
	}

	if (stack_idx == 1) {
		printf("%d", top(stack, stack_idx));
	}
	else {
		printf("0");
	}

	return 0;
}

void push(int stack[], int* idx, int data) {
	stack[(*idx)++] = data;
	return;
}

int pop(int stack[], int* idx) {
	return stack[--(*idx)];
}

int top(int stack[], int idx) {
	return stack[idx - 1];
}

bool is_empty(int idx) {
	return (idx) ? false : true;
}