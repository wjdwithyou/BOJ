#include <iostream>

#define MAX 100

int arr[MAX][MAX];

int main() {
    int n, m, x1, y1, x2, y2;
    int c = 0;
    
    scanf("%d %d", &n, &m);
    
    for (int k = 0; k < n; ++k) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        --x1; --x2; --y1; --y2;
        
        for (int i = y1; i <= y2; ++i) {
            for (int j = x1; j <= x2; ++j) {
                ++arr[i][j];
            }
        }
    }
    
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            if (arr[i][j] > m) {
                ++c;
            }
        }
    }
    
    return !printf("%d", c);
}