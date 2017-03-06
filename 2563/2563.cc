#include <iostream>

#define MAX 100

int arr[128][128];

int main() {
    int n, x, y;
    int sum = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        
        for (int j = y; j < y + 10; ++j) {
            for (int k = x; k < x + 10; ++k) {
                arr[j][k] = 1;
            }
        }
    }
    
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            sum += arr[i][j];
        }
    }
    
    printf("%d", sum);
    return 0;
}