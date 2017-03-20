#include <iostream>
#include <cstring>

char arr[128][128];
bool chk[128][128];

void dfs(int, int, int);

int main() {
    int n, cnt;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", arr[i]);
    }
    
    for (int k = 0;; ++k) {
        cnt = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!chk[i][j]) {
                    dfs(n, i, j);
                    ++cnt;
                }
            }
        }
        
        printf("%d ", cnt);
        
        if (k == 1) {
            break;
        }
        
        memset(chk, 0, sizeof(chk));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr[i][j] == 'G') {
                    arr[i][j] = 'R';
                }
            }
        }
    }
    
    return 0;
}

void dfs(int n, int i, int j) {
    ++chk[i][j];
    
    if (i < n - 1 && arr[i + 1][j] == arr[i][j] && !chk[i + 1][j]) {
        dfs(n, i + 1, j);
    }
    if (j < n - 1 && arr[i][j + 1] == arr[i][j] && !chk[i][j + 1]) {
        dfs(n, i, j + 1);
    }
    if (i > 0 && arr[i - 1][j] == arr[i][j] && !chk[i - 1][j]) {
        dfs(n, i - 1, j);
    }
    if (j > 0 && arr[i][j - 1] == arr[i][j] && !chk[i][j - 1]) {
        dfs(n, i, j - 1);
    }
    
    return;
}