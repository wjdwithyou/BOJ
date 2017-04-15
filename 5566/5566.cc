#include <iostream>

int board[1024];

int main() {
    int n, m, t;
    int cnt = 0, x = 1;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &board[i]);
    }
    
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &t);
        
        if (cnt) {
            continue;
        }
        
        x += t;
        
        if (n <= x) {
            cnt = i;
            continue;
        }
        
        x += board[x];
        
        if (n <= x) {
            cnt = i;
            continue;
        }
    }
    
    printf("%d", cnt);
    return 0;
}