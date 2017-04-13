#include <iostream>

int main() {
    long long fib[128];
    int n;
    
    fib[0] = 0;
    fib[1] = 1;
    
    scanf("%d", &n);
    
    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    printf("%lld", fib[n]);
    return 0;
}