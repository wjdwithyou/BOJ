#include <iostream>

int main() {
    int fib[64];
    int k;
    
    scanf("%d", &k);
    
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i <= k; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    printf("%d %d", fib[k - 1], fib[k]);
    return 0;
}