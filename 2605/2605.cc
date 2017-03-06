#include <iostream>

int main() {
    int arr[128];
    int n, t;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        
        for (int j = 0; j < t; ++j) {
            arr[i - j] = arr[i - j - 1];
        }
        
        arr[i - t] = i;
    }
    
    for (int i = 1; i <= n; ++i) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}