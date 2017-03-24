#include <iostream>

char arr[8192][8192];

void setStar(int, int, int);

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2 * n - 1; ++j) {
            arr[i][j] = ' ';
        }
    }
    
    setStar(n, n - 1, 0);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2 * n - 1; ++j) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

void setStar(int n, int x, int y) {
    if (n == 3) {
        arr[y][x] = arr[y + 1][x - 1] = arr[y + 1][x + 1] = '*';
        
        for (int i = -2; i <= 2; ++i) {
            arr[y + 2][x + i] = '*';
        }
        
        return;
    }
    
    setStar(n >> 1, x, y);
    setStar(n >> 1, x - (n >> 1), y + (n >> 1));
    setStar(n >> 1, x + (n >> 1), y + (n >> 1));
    
    return;
}