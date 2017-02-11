#include <iostream>
#include <cmath>

int main() {
    int x[2], y[2], z[2];
    int t, n, cx, cy, r, s;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        s = 0;
        
        for (int k = 0; k < 2; ++k) {
            scanf("%d %d", &x[k], &y[k]);
        }
        
        scanf("%d", &n);
        
        for (int j = 0; j < n; ++j) {
            scanf("%d %d %d", &cx, &cy, &r);
            
            for (int k = 0; k < 2; ++k) {
                z[k] = (pow(x[k] - cx, 2) + pow(y[k] - cy, 2) < pow(r, 2)) ? 1 : 0;
            }
            
            s += (z[0] != z[1]);
        }
        
        printf("%d\n", s);
    }
    
    return 0;
}