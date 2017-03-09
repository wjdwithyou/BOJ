#include <iostream>

int main() {
    int n, a, b;
    int ca = 0, cb = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        
        if (a > b) {
            ++ca;
        } else if (a < b) {
            ++cb;
        } else;
    }
    
    printf("%d %d", ca, cb);
    return 0;
}