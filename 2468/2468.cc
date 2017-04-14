#include <iostream>

typedef struct Location {
    int height;
    int chk;
}Location;

Location arr[128][128];

void dfs(int, int, int, int);

int main() {
    int n, cnt;
    int mh = 0, max = 1;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j].height);
            
            if (mh < arr[i][j].height) {
                mh = arr[i][j].height;
            }
        }
    }
    
    for (int i = 1; i < mh; ++i) {
        cnt = 0;
        
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < n; ++b) {
                arr[a][b].chk = 0;
            }
        }
        
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < n; ++b) {
                if (!arr[a][b].chk && arr[a][b].height > i) {
                    dfs(n, i, b, a);
                    ++cnt;
                }
            }
        }
        
        if (max < cnt) {
            max = cnt;
        }
    }
    
    printf("%d", max);
    return 0;
}

void dfs(int n, int i, int x, int y) {
    ++arr[y][x].chk;
    
    if (y + 1 < n && !arr[y + 1][x].chk && arr[y + 1][x].height > i) {
        dfs(n, i, x, y + 1);
    }
    if (x + 1 < n && !arr[y][x + 1].chk && arr[y][x + 1].height > i) {
        dfs(n, i, x + 1, y);
    }
    if (y > 0 && !arr[y - 1][x].chk && arr[y - 1][x].height > i) {
        dfs(n, i, x, y - 1);
    }
    if (x > 0 && !arr[y][x - 1].chk && arr[y][x - 1].height > i) {
        dfs(n, i, x - 1, y);
    }
    
    return;
}