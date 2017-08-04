#include <iostream>

int main() {
    long long n;
    
    scanf("%lld", &n);
    
    return !printf("%s", (n & 1) ? "SK" : "CY");
}