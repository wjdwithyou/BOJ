#include <iostream>

int arr[512][512];

int main() {
    int n, t;
    int max = -1;
    
    scanf("%d", &n);
    scanf("%d", &arr[1][1]);
    
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            scanf("%d", &t);
            
            if (j == 1) {
                arr[i][j] = t + arr[i - 1][j];
            }
            else if (j == i) {
                arr[i][j] = t + arr[i - 1][j - 1];
            }
            else {
                arr[i][j] = t + ((arr[i - 1][j - 1] > arr[i - 1][j]) ? arr[i - 1][j - 1] : arr[i - 1][j]);
            }
        }
    }
    
    for (int j = 1; j <= n; ++j) {
        if (max < arr[n][j]) {
            max = arr[n][j];
        }
    }
    
    printf("%d", max);
    return 0;
}