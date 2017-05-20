#include <iostream>

int main() {
    int arr[32];
    int n, b;
    int idx = 0;
    
    scanf("%d %d", &n, &b);
    
    while (n) {
        arr[idx++] = n % b;
        n /= b;
    }
    
    for (int i = idx - 1; i >= 0; --i) {
        printf("%c", arr[i] + ((arr[i] < 10) ? '0' : 'A' - 10));
    }
    
    return 0;
}