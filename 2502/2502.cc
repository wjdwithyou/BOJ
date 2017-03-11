#include <iostream>

int main() {
    int fib[32];
    int d, k, ca, cb, t;
    
    scanf("%d %d", &d, &k);
    
    fib[1] = 0;
    fib[2] = 1;
    
    for (int i = 3; i <= d; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    ca = fib[d - 1];
    cb = fib[d];
    
    for (int i = 1;; ++i) {
        t = k - (ca * i);
        
        if (!(t % cb)) {
            printf("%d\n%d", i, t / cb);
            break;
        }
    }
    
    return 0;
}