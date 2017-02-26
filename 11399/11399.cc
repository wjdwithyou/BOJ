#include <iostream>

int arr[1024];

int main() {
    int n, idx, temp;
    int sum = 0;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 1; i <= n; ++i) {
        idx = i;
        
        for (int j = i + 1; j <= n; ++j) {
            if (arr[idx] < arr[j]) {
                idx = j;
            }
        }
        
        temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
    
    for (int i = 1; i <= n; ++i) {
        sum += (arr[i] * i);
    }
    
    printf("%d", sum);
    return 0;
}