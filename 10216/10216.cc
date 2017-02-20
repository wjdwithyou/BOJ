#include <iostream>
#include <cstring>
#include <cmath>

typedef struct Tower {
    int x;
    int y;
    int r;
    int chk;
}Tower;

Tower arr[4096];

void dfs(int, int);

int main() {
    int t, n, cnt;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        memset(arr, 0, sizeof(arr));
        cnt = 0;
        
        scanf("%d", &n);
        
        for (int j = 0; j < n; ++j) {
            scanf("%d %d %d", &arr[j].x, &arr[j].y, &arr[j].r);
        }
        
        for (int j = 0; j < n; ++j) {
            if (!arr[j].chk) {
                ++cnt;
                dfs(n, j);
            }
        }
        
        printf("%d\n", cnt);
    }
    
    return 0;
}

void dfs(int n, int tower) {
    double d;
    
    ++arr[tower].chk;
    
    for (int i = 0; i < n; ++i) {
        if (arr[i].chk) {
            continue;
        }
        
        d = sqrt(pow(arr[i].x - arr[tower].x, 2) + pow(arr[i].y - arr[tower].y, 2));
        
        if (d > arr[i].r + arr[tower].r) {
            continue;
        }
        
        dfs(n, i);
    }
    
    return;
}