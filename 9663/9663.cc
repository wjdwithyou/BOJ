#include <iostream>

int dfs(int[][16], int, int, int);

int main() {
    int board[16][16] = { 0, };
    int n;
    int sum = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        sum += dfs(board, n, i, 0);
    }
    
    printf("%d", sum);
    return 0;
}

int dfs(int prev[][16], int n, int r, int qn) {
    if (++qn == n) {
        return 1;
    }
    
    int board[16][16];
    int sum = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = prev[i][j];
        }
    }
    
    for (int j = qn; j < n; ++j) {
        board[r][j] = 1;
    }
    for (int j = qn, k = r - 1; j < n && k >= 0; ++j, --k) {
        board[k][j] = 1;
    }
    for (int j = qn, k = r + 1; j < n && k < n; ++j, ++k) {
        board[k][j] = 1;
    }
    
    for (int i = 0; i < n; ++i) {
        if (!board[i][qn]) {
            sum += dfs(board, n, i, qn);
        }
    }
    
    return sum;
}