#include <iostream>

int arr[16384];

int main() {
    long long sum = 0;
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        
        for (int j = 0; j < i; ++j) {
            sum += abs(arr[i] - arr[j]);
        }
    }
    
    return !printf("%lld", sum << 1);
}