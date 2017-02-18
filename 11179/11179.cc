#include <iostream>

int main() {
    int arr[32];
    int n, idx;
    
    scanf("%d", &n);
    
    for (idx = 0; n > 0; n >>= 1) {
        arr[idx++] = (n & 1);
    }
    
    for (int i = 0;; n <<= 1) {
        n += arr[i++];
        
        if (i >= idx) {
            break;
        }
    }
    
    printf("%d", n);
    return 0;
}