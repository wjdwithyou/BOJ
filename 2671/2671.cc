#include <iostream>

int data[16][4] = {
	{ 5, 1, 0 },
	{ 2, 9, 0 },
	{ 3, 9, 0 },
	{ 3, 4, 0 },
	{ 5, 8, 1 },
	{ 9, 6, 0 },
	{ 5, 1, 1 },
	{ 3, 6, 0 },
	{ 7, 8, 1 },
	{ 9, 9, 0 }
};

int main() {
	char sound[256];
	int cur = 0;
    
	scanf("%s", sound);
    
	for (int j = 0; sound[j] != '\0'; ++j) {
		cur = data[cur][sound[j] - '0'];
	}
    
	printf("%s", (data[cur][2]) ? "SUBMARINE" : "NOISE");
	return 0;
}