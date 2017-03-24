#include <iostream>

char arr[4096][4096];

void setStar(int, int, int);

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = ' ';
        }
    }
    
    setStar(n, 0, 0);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

void setStar(int n, int x, int y) {
    if (n == 1) {
        arr[y][x] = '*';
        return;
    }
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) {
                continue;
            }
            
            int nn = n / 3;
            
            setStar(nn, x + j * nn, y + i * nn);
        }
    }
    
    return;
}