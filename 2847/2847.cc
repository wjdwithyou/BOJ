#include <iostream>

int main() {
    int arr[128];
    int n, t;
    int cnt = 0;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = n - 1; i > 0; --i) {
        if (arr[i] < arr[i + 1]) {
            continue;
        }
        
        t = arr[i + 1] - 1;
        
        cnt += arr[i] - t;
        arr[i] = t;
    }
    
    return !printf("%d", cnt);
}