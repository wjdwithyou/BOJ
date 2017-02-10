#include <iostream>

int main() {
    int arr[16][16] = { 0, };
    int n, k;
    
    arr[1][0] = arr[1][1] = 1;
    
    for (int i = 2; i <= 10; ++i) {
        for (int j = 0; j <= i; ++j) {
            arr[i][j] = (j == 0) ? 1 : arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    
    scanf("%d %d", &n, &k);
    printf("%d", arr[n][k]);
    
    return 0;
}