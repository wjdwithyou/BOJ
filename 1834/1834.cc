#include <iostream>

int main() {
    int n;
    unsigned long long int sum = 0;
    
    scanf("%d", &n);
    
    for (int i = 1; i < n; ++i) {
        sum += (n * i + i);
    }
    
    printf("%llu", sum);
    return 0;
}