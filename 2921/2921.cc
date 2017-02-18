#include <iostream>

int arr[1024];

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        arr[i] = arr[i - 1] + ((3 * i * (i + 1)) >> 1);
    }
    
    printf("%d", arr[n]);
    return 0;
}