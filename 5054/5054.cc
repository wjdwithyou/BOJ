#include <iostream>

int main() {
    int t, n, l, min, max;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        min = 100, max = -1;
        
        scanf("%d", &n);
        
        for (int j = 0; j < n; ++j) {
            scanf("%d", &l);
            
            if (min > l) {
                min = l;
            }
            if (max < l) {
                max = l;
            }
        }
        
        printf("%d\n", 2 * (max - min));
    }
    
    return 0;
}