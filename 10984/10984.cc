#include <iostream>

int main() {
    int t, n, c, csum;
    float g, gsum;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        csum = 0;
        gsum = 0;
        
        scanf("%d", &n);
        
        for (int j = 0; j < n; ++j) {
            scanf("%d %f", &c, &g);
            
            csum += c;
            gsum += c * g;
        }
        
        printf("%d %.1f\n", csum, gsum / csum);
    }
    
    return 0;
}