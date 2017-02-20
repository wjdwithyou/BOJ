#include <iostream>

int arr[1024][1024];

void dfs(int, int);

int main() {
    int n, m, a, b;
    int cnt = 0;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        arr[a][b] = arr[b][a] = 1;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!arr[i][0]) {
            dfs(n, i);
            ++cnt;
        }
    }
    
    printf("%d", cnt);
    return 0;
}

void dfs(int n, int v) {
    ++arr[v][0];
    
    for (int i = 1; i <= n; ++i) {
        if (arr[v][i] && !arr[i][0]) {
            dfs(n, i);
        }
    }
    
    return;
}