#include <iostream>

int main() {
	char buf[128];
	char mapping[32] = "yhesocvxduiglbkrztnwjpfmaq";
	int t;

	scanf("%d", &t);

	while (getchar() != '\n');

	for (int i = 1; i <= t; ++i) {
		fgets(buf, 128, stdin);

		for (int j = 0; buf[j] != '\0'; ++j) {
			if (buf[j] == ' ');
			else if (buf[j] == '\n') {
				buf[j] = '\0';
			}
			else {
				buf[j] = mapping[buf[j] - 'a'];
			}
		}

		printf("Case #%d: %s\n", i, buf);
	}

	return 0;
}