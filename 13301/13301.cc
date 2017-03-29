#include <iostream>

long long fib[128];

int main() {
    int n;
    
    fib[1] = 2;
    fib[2] = 3;
    
    scanf("%d", &n);
    
    for (int i = 3; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    printf("%lld", fib[n] << 1);
    return 0;
}