#include <iostream>

#define LIMIT 210

int main() {
    int s = 0;
    int k, n, t;
    char z;
    
    scanf("%d %d", &k, &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %c", &t, &z);
        
        s += t;
        
        if (s > LIMIT) {
            break;
        }
        
        if (z == 'T') {
            k = k % 8 + 1;
        }
    }
    
    return !printf("%d", k);
}