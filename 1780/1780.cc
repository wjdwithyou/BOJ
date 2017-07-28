#include <iostream>

#define MAX 2187

int arr[MAX][MAX];

void divide(int, int, int, int, int[]);

int main() {
    int cnt[4] = { 0 };
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    divide(0, 0, n, n, cnt);
    
    for (int i = 0; i < 3; ++i) {
        printf("%d\n", cnt[i]);
    }
    
    return 0;
}

void divide(int x1, int y1, int x2, int y2, int cnt[]) {
    int k = arr[y1][x1];
    int chk = 0;
    
    for (int i = y1; i < y2; ++i) {
        for (int j = x1; j < x2; ++j) {
            if (arr[i][j] != k) {
                ++chk;
                break;
            }
        }
    }
    
    if (!chk) {
        ++cnt[++k];
    } else {
        int t = (x2 - x1) / 3;
        
        for (int a = y1; a < y2; a += t) {
            for (int b = x1; b < x2; b += t) {
                divide(b, a, b + t, a + t, cnt);
            }
        }
    }
    
    return;
}