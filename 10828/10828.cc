#include <iostream>

int stack[10000];

int main() {
	char buf[16];
	int n, num;
	int stack_idx = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%s", buf);

		switch (buf[0]) {
		case 'p':
			if (buf[1] == 'u') {
				scanf("%d", &num);
				stack[stack_idx++] = num;
			}
			else {
				if (stack_idx == 0) {
					puts("-1");
				}
				else {
					printf("%d\n", stack[--stack_idx]);
				}
			}
			break;
		case 's':
			printf("%d\n", stack_idx);
			break;
		case 'e':
			if (stack_idx == 0) {
				puts("1");
			}
			else {
				puts("0");
			}
			break;
		case 't':
			if (stack_idx == 0) {
				puts("-1");
			}
			else {
				printf("%d\n", stack[stack_idx - 1]);
			}
			break;
		default:
			break;
		}
	}

	return 0;
}