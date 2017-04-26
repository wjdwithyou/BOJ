#include <iostream>

#define DIV 1000000000

int fib[1048576];

int main() {
    int n;
    
    scanf("%d", &n);
    
    if (!n) {
        puts("0");
    } else if (n < 0 && !(n & 1)) {
        puts("-1");
    } else {
        puts("1");
    }
    
    n = abs(n);
    
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i <= n; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % DIV;
    }
    
    return !printf("%d", fib[n]);
}