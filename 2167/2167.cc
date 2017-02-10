#include <iostream>

int arr[512][512];

int main() {
    int n, m, k, s, ii, jj, xx, yy;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    scanf("%d", &k);
    
    for (int a = 0; a < k; ++a) {
        s = 0;
        
        scanf("%d %d %d %d", &ii, &jj, &xx, &yy);
        
        for (int i = ii; i <= xx; ++i) {
            for (int j = jj; j <= yy; ++j) {
                s += arr[i][j];
            }
        }
        
        printf("%d\n", s);
    }
    
    return 0;
}