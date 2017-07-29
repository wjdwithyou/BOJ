#include <iostream>

int main() {
    int arr[16];
    int n, k;
    int sum = 0, cnt = 0;
    
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = n - 1; i >= 0 && sum < k; --i) {
        while (sum + arr[i] <= k) {
            sum += arr[i];
            ++cnt;
        }
    }
    
    return !printf("%d", cnt);
}