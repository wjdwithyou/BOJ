#include <iostream>

int main() {
    int t, n, x, sum;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        sum = 0;
        
        scanf("%d", &n);
        
        for (int j = 0; j < n; ++j) {
            scanf("%d", &x);
            
            sum += x;
        }
        
        printf("%d\n", sum);
    }
    
    return 0;
}