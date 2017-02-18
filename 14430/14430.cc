#include <iostream>

int map[512][512];

int main() {
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &map[i][j]);
            
            if (i == 1 && j == 1);
            else if (i == 1) {
                map[i][j] += map[i][j - 1];
            }
            else if (j == 1) {
                map[i][j] += map[i - 1][j];
            }
            else {
                map[i][j] += (map[i][j - 1] > map[i - 1][j]) ? map[i][j - 1] : map[i - 1][j];
            }
        }
    }
    
    printf("%d", map[n][m]);
    return 0;
}