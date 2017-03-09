#include <iostream>

int main() {
    int t, n, sum, min;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        sum = 0;
        min = 128;
        
        for (int j = 0; j < 7; ++j) {
            scanf("%d", &n);
            
            if (n & 1) {
                continue;
            }
            
            sum += n;
            
            if (min > n) {
                min = n;
            }
        }
        
        printf("%d %d\n", sum, min);
    }
    
    return 0;
}