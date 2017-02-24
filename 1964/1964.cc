#include <iostream>

int main() {
    unsigned long long int n;
    
    scanf("%llu", &n);
    printf("%llu", (5 + 3 * ((n * (n - 1)) >> 1) + 4 * (n - 1)) % 45678);
    
    return 0;
}