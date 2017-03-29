#include <iostream>

int a[128][128], b[128][128];

int main() {
    int n, m, k, t;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    
    scanf("%d %d", &m, &k);
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            scanf("%d", &b[i][j]);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            t = 0;
            
            for (int z = 0; z < m; ++z) {
                t += a[i][z] * b[z][j];
            }
            
            printf("%d ", t);
        }
        
        puts("");
    }
    
    return 0;
}