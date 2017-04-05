#include <iostream>

int vertex[128][128];

void dfs(int, int);

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &vertex[i][j]);
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (vertex[i][j]) {
                dfs(n, j);
            }
        }
        
        for (int j = 1; j <= n; ++j) {
            printf("%d ", vertex[j][0]);
            vertex[j][0] = 0;
        }
        
        puts("");
    }
    
    return 0;
}

void dfs(int n, int v) {
    vertex[v][0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        if (vertex[v][i] && !vertex[i][0]) {
            dfs(n, i);
        }
    }
    
    return;
}