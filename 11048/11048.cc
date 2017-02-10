#include <iostream>

int maze[1024][1024];

int main() {
    int n, m, t;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &t);
            
            if (i == 1) {
                maze[i][j] = t + ((j == 1) ? 0 : maze[i][j - 1]);
            }
            else if (j == 1) {
                maze[i][j] = t + maze[i - 1][j];
            }
            else {
                maze[i][j] = t + ((maze[i - 1][j] > maze[i][j - 1]) ? maze[i - 1][j] : maze[i][j - 1]);
            }
        }
    }
    
    printf("%d", maze[n][m]);
    return 0;
}