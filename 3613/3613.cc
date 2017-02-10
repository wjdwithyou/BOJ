#include <iostream>

int main() {
	char buf[128];
	int c = 0, j = 0;

	scanf("%s", buf);

	if (buf[0] < 'a' || buf[0] > 'z') {
		printf("Error!");
		return 0;
	}

	for (int i = 1; buf[i] != '\0'; ++i) {
		if (buf[i] == '_') {
			++c;

			if (buf[i + 1] == '_' || buf[i + 1] == '\0') {
				++j;
				break;
			}
		}
		else if (buf[i] >= 'A' && buf[i] <= 'Z') {
			++j;
		}
		else if (buf[i] >= 'a' && buf[i] <= 'z');
		else {
			++c, ++j;
			break;
		}
	}

	if (c && j) {
		printf("Error!");
	}
	else if (!c && !j) {
		printf("%s", buf);
	}
	else {
		for (int i = 0; buf[i] != '\0'; ++i) {
			if (c) {
				if (buf[i] == '_') {
					printf("%c", buf[++i] - 32);
				}
				else {
					printf("%c", buf[i]);
				}
			}
			else {
				if (buf[i] >= 'A' && buf[i] <= 'Z') {
					printf("_%c", buf[i] + 32);
				}
				else {
					printf("%c", buf[i]);
				}
			}
		}
	}

	return 0;
}