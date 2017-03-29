#include <iostream>

int main() {
    int t, n, e, sum;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        sum = 0;
        
        scanf("%d", &n);
        
        for (int j = 0; j < 6; ++j) {
            scanf("%d", &e);
            sum += e;
        }
        
        for (int k = 1;; ++k, sum *= 4) {
            if (n < sum) {
                printf("%d\n", k);
                break;
            }
        }
    }
    
    return 0;
}