#include <iostream>

int main() {
    int arr[128];
    int n, m, ii, jj, temp;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; ++i) {
        arr[i] = i;
    }
    
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &ii, &jj);
        
        temp = arr[ii];
        arr[ii] = arr[jj];
        arr[jj] = temp;
    }
    
    for (int i = 1; i <= n; ++i) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}