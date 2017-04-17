#include <iostream>

int arr[2][512][512];

int main() {
    int n, t;
    int cnt = 0;
    
    scanf("%d", &n);
    
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &arr[k][i][j]);
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            t = 0;
            
            for (int k = 0; k < n; ++k) {
                t |= (arr[0][i][k] & arr[1][k][j]);
            }
            
            cnt += t;
        }
    }
    
    printf("%d", cnt);
    return 0;
}