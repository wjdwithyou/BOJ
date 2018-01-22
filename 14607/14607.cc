#include <iostream>

int main(void) {
	setbuf(stdout, NULL);
    
	long long n;
    
	scanf("%lld", &n);
    
	return !printf("%lld", (n * (n - 1)) >> 1);
}