#include <iostream>

int arr[32][32];

int main() {
    int t, n, m;
    
    for (int j = 1; j <= 30; ++j) {
        arr[1][j] = j;
    }
    
    for (int i = 2; i <= 30; ++i) {
        for (int j = i; j <= 30; ++j) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i][j - 1];
        }
    }
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d %d", &n, &m);
        printf("%d\n", arr[n][m]);
    }
    
    return 0;
}