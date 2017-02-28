#include <iostream>

int main() {
    int t, n;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d", &n);
        
        for (int j = 0; n > 0; ++j, n >>= 1) {
            if (n & 1) {
                printf("%d ", j);
            }
        }
        
        printf("\n");
    }
    
    return 0;
}