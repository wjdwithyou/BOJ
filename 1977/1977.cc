#include <iostream>

int main() {
    int m, n, t;
    int min = 0, sum = 0;
    
    scanf("%d", &m);
    scanf("%d", &n);
    
    for (int i = 1; i <= 100; ++i) {
        t = i * i;
        
        if (m <= t && n >= t) {
            sum += t;
            
            if (!min) {
                min = t;
            }
        }
    }
    
    (!min) ? printf("-1") : printf("%d\n%d", sum, min);
    return 0;
}