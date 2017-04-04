#include <iostream>

long long arr[1048576], fenwick[1048576];

int main() {
    int n, m, k, a, b;
    long long c, t, sum;
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &arr[i]);
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (i & -i); ++j) {
            fenwick[i] += arr[i - j];
        }
    }
    
    for (int i = m + k; i > 0; --i) {
        scanf("%d %d %lld", &a, &b, &c);
        
        if (a & 1) {
            t = c - arr[b];
            arr[b] = c;
            
            for (; b <= n; b += (b & -b)) {
                fenwick[b] += t;
            }
        } else {
            sum = 0;
            
            for (; c; c -= (c & -c)) {
                sum += fenwick[c];
            }
            for (--b; b; b -= (b & -b)) {
                sum -= fenwick[b];
            }
            
            printf("%lld\n", sum);
        }
    }
    
    return 0;
}