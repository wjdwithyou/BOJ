#include <iostream>

int main() {
    int t, d, n, s, p;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d %d %d %d", &d, &n, &s, &p);
        
        if (n * s > n * p + d) {
            puts("parallelize");
        } else if (n * s < n * p + d) {
            puts("do not parallelize");
        } else {
            puts("does not matter");
        }
    }
    
    return 0;
}