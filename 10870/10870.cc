#include <iostream>

int main() {
    int fib[32] = { 0, 1 };
    int n;
    
    scanf("%d", &n);
    
    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    return !printf("%d", fib[n]);
}