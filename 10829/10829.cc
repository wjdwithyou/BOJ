#include <iostream>

int main() {
    int arr[64];
    long long n;
    int idx = 0;
    
    scanf("%lld", &n);
    
    for (; n; n >>= 1) {
        arr[idx++] = n & 1;
    }
    
    do {
        printf("%d", arr[--idx]);
    } while (idx);
    
    return 0;
}