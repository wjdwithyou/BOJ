#include <iostream>

int main() {
    int k, ingredient, constant, w, n, d;
    
    scanf("%d", &k);
    
    for (int i = 1; i <= k; ++i) {
        scanf("%d %d", &ingredient, &constant);
        printf("Data Set %d:\n", i);
        
        for (int j = 0; j < ingredient; ++j) {
            scanf("%d %d/%d", &w, &n, &d);
            
            w *= constant;
            n *= constant;
            
            if (d <= n) {
                w += (n / d);
                n %= d;
            }
            
            while (n != 0 && n != 1 && d % n == 0) {
                n >>= 1, d >>= 1;
            }
            
            (n == 0) ? printf("%d\n", w) : printf("%d %d/%d\n", w, n, d);
        }
        printf("\n");
    }
    
    return 0;
}