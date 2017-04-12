#include <iostream>

int getRouteCnt(int[][16], int, int, int, int);

int main() {
    int arr[16][16];
    int n, m, k, r, c, cnt;
    
    scanf("%d %d %d", &n, &m, &k);
    
    if (k--) {
        r = k / m;
        c = k % m;
        
        cnt = getRouteCnt(arr, 0, 0, c, r) * getRouteCnt(arr, c, r, m - 1, n - 1);
    } else {
        cnt = getRouteCnt(arr, 0, 0, m - 1, n - 1);
    }
    
    printf("%d", cnt);
    return 0;
}

int getRouteCnt(int arr[][16], int x1, int y1, int x2, int y2) {
    for (int i = y1; i <= y2; ++i) {
        arr[i][x1] = 1;
    }
    for (int j = x1; j <= x2; ++j) {
        arr[y1][j] = 1;
    }
    
    for (int i = y1 + 1; i <= y2; ++i) {
        for (int j = x1 + 1; j <= x2; ++j) {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    
    return arr[y2][x2];
}