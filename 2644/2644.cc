#include <iostream>

int arr[128][128];

int dfs(int, int, int);

int main() {
    int n, a, b, m, x, y;
    
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &m);
    
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        
        ++arr[x][y];
        ++arr[y][x];
    }
    
    printf("%d", dfs(n, a, b));
    return 0;
}

int dfs(int n, int a, int b) {
    if (a == b) {
        return 0;
    }
    
    int t;
    
    ++arr[b][0];
    
    for (int i = 1; i <= n; ++i) {
        if (arr[b][i] && !arr[i][0]) {
            t = dfs(n, a, i);
            
            if (t != -1) {
                return ++t;
            }
        }
    }
    
    return -1;
}