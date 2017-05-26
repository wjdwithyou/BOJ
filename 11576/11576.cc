#include <iostream>
#include <cmath>

#define MAX 1048576

int main() {
    int a, b, m, t, max, d, q;
    int n = 0, chk = 0;
    
    scanf("%d %d %d", &a, &b, &m);
    
    for (int i = m - 1; i >= 0; --i) {
        scanf("%d", &t);
        n += t * static_cast<int>(pow(a, i));
    }
    
    for (max = 2; pow(b, max) < MAX; ++max);
    
    for (int i = --max; i >= 0; --i, n -= q * d) {
        d = static_cast<int>(pow(b, i));
        q = n / d;
        
        if (!chk && !q) {
            continue;
        }
        
        ++chk;
        printf("%d ", q);
    }
    
    return 0;
}