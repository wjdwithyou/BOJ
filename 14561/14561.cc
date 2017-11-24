#include <iostream>

int main(void) {
    int arr[64];
    long long a, n, d;
    int T, len, chk;
    
    scanf("%d", &T);
    
    for (int Ti = 0; Ti < T; ++Ti) {
        scanf("%lld %lld", &a, &n);
        
        for (d = 1; d * n <= a; d *= n);
        
        for (len = 0; d; ++len) {
            arr[len] = static_cast<int>(a / d);
            a %= d;
            d /= n;
        }
        
        chk = 1;
        
        for (int i = 0, j = --len; i < j; ++i, --j) {
            if (arr[i] != arr[j]) {
                --chk;
                break;
            }
        }
        
        printf("%d\n", chk);
    }
    
    return 0;
}