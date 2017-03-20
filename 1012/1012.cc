#include <iostream>
#include <cstring>

int arr[64][64];

void dfs(int, int, int, int);

int main() {
    int t, m, n, k, tx, ty, cnt;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        memset(arr, 0, sizeof(arr));
        cnt = 0;
        
        scanf("%d %d %d", &m, &n, &k);
        
        for (int j = 0; j < k; ++j) {
            scanf("%d %d", &tx, &ty);
            ++arr[ty][tx];
        }
        
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < m; ++b) {
                if (arr[a][b]) {
                    dfs(n, m, a, b);
                    ++cnt;
                }
            }
        }
        
        printf("%d\n", cnt);
    }
    
    return 0;
}

void dfs(int my, int mx, int y, int x) {
    --arr[y][x];
    
    if (y < my - 1 && arr[y + 1][x]) {
        dfs(my, mx, y + 1, x);
    }
    if (x < mx - 1 && arr[y][x + 1]) {
        dfs(my, mx, y, x + 1);
    }
    if (y > 0 && arr[y - 1][x]) {
        dfs(my, mx, y - 1, x);
    }
    if (x > 0 && arr[y][x - 1]) {
        dfs(my, mx, y, x - 1);
    }
    
    return;
}