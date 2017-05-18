#include <iostream>

#define DIV 1000007
#define MAX 200

long long arr[256][256];

int main() {
    int w, h, x, y;
    
    for (int j = 0; j < MAX; ++j) {
        arr[0][j] = 1;
    }
    
    for (int i = 1; i < MAX; ++i) {
        arr[i][0] = 1;
        
        for (int j = 1; j < MAX; ++j) {
            arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % DIV;
        }
    }
    
    scanf("%d %d %d %d", &w, &h, &x, &y);
    
    return !printf("%lld", (arr[y - 1][x - 1] * arr[h - y][w - x]) % DIV);
}