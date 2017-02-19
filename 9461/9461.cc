#include <iostream>

int main() {
    unsigned long long int arr[128] = { 0, 1, 1, 1, 2, 2 };
    int t, n;
    
    for (int i = 6; i <= 100; ++i) {
        arr[i] = arr[i - 1] + arr[i - 5];
    }
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d", &n);
        printf("%llu\n", arr[n]);
    }
    
    return 0;
}