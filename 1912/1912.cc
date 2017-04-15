#include <iostream>

int arr[131072];

int main() {
    int n, t, max;
    
    scanf("%d", &n);
    scanf("%d", &arr[0]);
    
    max = arr[0];
    
    for (int i = 1; i < n; ++i) {
        scanf("%d", &t);
        arr[i] = (arr[i - 1] + t > t) ? arr[i - 1] + t : t;
        
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    
    printf("%d", max);
    return 0;
}