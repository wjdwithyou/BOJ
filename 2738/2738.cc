#include <iostream>

int arr[128][128];

int main() {
    int n, m, t;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &t);
            printf("%d ", arr[i][j] + t);
        }
        printf("\n");
    }
    
    return 0;
}