#include <iostream>

int arr[1024];

void dfs(int);

int main() {
    int t, n, cnt;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        cnt = 0;
        
        scanf("%d", &n);
        
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &arr[j]);
        }
        
        for (int j = 1; j <= n; ++j) {
            if (arr[j]) {
                dfs(j);
                ++cnt;
            }
        }
        
        printf("%d\n", cnt);
    }
    
    return 0;
}

void dfs(int num) {
    int next = arr[num];
    
    arr[num] = 0;
    
    if (arr[next]) {
        dfs(next);
    }
    
    return;
}