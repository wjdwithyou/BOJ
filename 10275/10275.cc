#include <iostream>

int getDate(int, long long, long long);

int main() {
    long long a, b;
    int t, n;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d %lld %lld", &n, &a, &b);
        printf("%d\n", getDate(n, a, b));
    }
    
    return 0;
}

int getDate(int n, long long a, long long b) {
    int r = 0;
    
    while (!(a & 1) && !(b & 1)) {
        a >>= 1;
        b >>= 1;
        r += 1;
    }
    
    return n - r;
}