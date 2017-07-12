#include <iostream>

#define MAX 1024

int arr[MAX + 1][MAX + 1];

int main() {
    int n, m, t, s, x1, y1, x2, y2;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &t);
            arr[i][j] = arr[i][j - 1] + t;
        }
    }
    
    for (int k = 0; k < m; ++k) {
        s = 0;
        
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        
        for (int i = y1; i <= y2; ++i) {
            s += arr[i][x2] - arr[i][x1 - 1];
        }
        
        printf("%d\n", s);
    }
    
    return 0;
}