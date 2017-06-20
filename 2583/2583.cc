#include <iostream>

int arr[128][128];
int area[8192];

int dfs(int, int, int, int);

int main() {
    int n, m, k, x1, y1, x2, y2, idx, temp;
    int cnt = 0;
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (int i = 0; i < k; ++i) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        for (int b = y1; b < y2; ++b) {
            for (int a = x1; a < x2; ++a) {
                ++arr[b][a];
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!arr[i][j]) {
                area[cnt++] = dfs(m, n, j, i);
            }
        }
    }
    
    for (int i = 0; i < cnt; ++i) {
        idx = i;
        
        for (int j = i + 1; j < cnt; ++j) {
            if (area[idx] > area[j]) {
                idx = j;
            }
        }
        
        if (idx == i) {
            continue;
        }
        
        temp = area[i];
        area[i] = area[idx];
        area[idx] = temp;
    }
    
    printf("%d\n", cnt);
    
    for (int i = 0; i < cnt; ++i) {
        printf("%d ", area[i]);
    }
    
    return 0;
}

int dfs(int m, int n, int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n || arr[y][x]) {
        return 0;
    }
    
    int s = 1;
    
    ++arr[y][x];
    
    s += dfs(m, n, x, y + 1);
    s += dfs(m, n, x + 1, y);
    s += dfs(m, n, x, y - 1);
    s += dfs(m, n, x - 1, y);
    
    return s;
}