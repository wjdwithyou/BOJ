#include <iostream>

int main() {
    int a;
	(((intptr_t)&a >> 4) & 1) ? printf("Korea") : printf("Yonsei");
	return 0;
}