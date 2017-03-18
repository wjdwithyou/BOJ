#include <iostream>

int a[1048576];

int main() {
    int n, m, t;
    int idx = 0;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < m; ++i) {
        scanf("%d", &t);
        
        while (idx < n && a[idx] <= t) {
            printf("%d ", a[idx++]);
        }
        
        printf("%d ", t);
    }
    
    while (idx < n) {
        printf("%d ", a[idx++]);
    }
    
    return 0;
}