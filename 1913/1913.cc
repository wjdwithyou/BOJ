#include <iostream>

int arr[1024][1024];

int main() {
    int n, num, x, y;
    int cnt = 0;
    
    scanf("%d", &n);
    scanf("%d", &num);
    
    x = y = (n >> 1);
    
    for (int i = 1;; i += 2) {
        for (int j = 0; j < i; ++j) {
            arr[y--][x] = ++cnt;
        }
        
        if (i >= n) {
            break;
        }
        
        for (int j = 0; j < i; ++j) {
            arr[y][x++] = ++cnt;
        }
        for (int j = 0; j <= i; ++j) {
            arr[y++][x] = ++cnt;
        }
        for (int j = 0; j <= i; ++j) {
            arr[y][x--] = ++cnt;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == num) {
                y = i, x = j;
            }
            
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("%d %d", ++y, ++x);
    
    return 0;
}