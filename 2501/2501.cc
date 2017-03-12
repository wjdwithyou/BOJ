#include <iostream>

int arr[16384];

int main() {
    int n, k, m;
    int cnt = 0;
    
    scanf("%d %d", &n, &k);
    
    m = n;
    
    for (int i = 1; i < m; ++i) {
        if (!(n % i)) {
            arr[i] = arr[n / i] = 1;
            m = n / i;
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (arr[i]) {
            if (++cnt == k) {
                printf("%d", i);
                break;
            }
        }
    }
    
    if (cnt < k) {
        printf("0");
    }
    
    return 0;
}