#include <iostream>

int main(void) {
    long long t[64];
    int n;
    
    setbuf(stdout, NULL);
    
    scanf("%d", &n);
    
    t[0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        t[i] = 0;
        
        for (int j = 0; j < i; ++j) {
            t[i] += t[j] * t[i - j - 1];
        }
    }
    
    return !printf("%lld", t[n]);
}