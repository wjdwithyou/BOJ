#include <iostream>
#include <cstring>

int arr[131072];
char p[131072];
char buf[524288];

int main() {
	int t, n;
	int front, back, temp;
	char* ptr;
	bool rev, chk;

	scanf("%d", &t);

	for (int i = 0; i < t; ++i) {
		front = back = 0;
		rev = chk = false;

		scanf("%s", p);
		scanf("%d", &n);
		scanf("%s", buf);

		ptr = strtok(buf, ",");
		temp = atoi(++ptr);

		if (temp) {
			arr[back++] = temp;
		}

		while (ptr = strtok(NULL, ",")) {
			temp = atoi(ptr);

			if (temp) {
				arr[back++] = temp;
			}
		}

		for (int j = 0; p[j] != '\0'; ++j) {
			if (p[j] == 'R') {
				rev = !rev;
			}
			else {
				if (front == back) {
					chk = true;
					break;
				}

				(!rev) ? ++front : --back;
			}
		}

		if (chk) {
			puts("error");
		}
		else {
			printf("[");
			if (!rev) {
				for (int j = front; j < back; ++j) {
					printf((j == front) ? "%d" : ",%d", arr[j]);
				}
			}
			else {
				for (int j = back - 1; j >= front; --j) {
					printf((j == front) ? "%d" : "%d,", arr[j]);
				}
			}
			puts("]");
		}
	}

	return 0;
}