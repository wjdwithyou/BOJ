#include <iostream>

int arr[1024];

int main() {
    int n;
    
    arr[1] = 1;
    arr[2] = 2;
    
    scanf("%d", &n);
    
    for (int i = 3; i <= n; ++i) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    }
    
    printf("%d", arr[n]);
    return 0;
}