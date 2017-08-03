#include <iostream>

long long fw[1048576];

long long getSum(int, int);

int main() {
    int n, m, a, b, c, t;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        
        if (!a) {
            if (b > c) {
                t = b;
                b = c;
                c = t;
            }
            
            printf("%lld\n", getSum(b, c));
            continue;
        }
        
        for (long long t = c - getSum(b, b); b <= n; b += (b & -b)) {
            fw[b] += t;
        }
    }
    
    return 0;
}

long long getSum(int b, int c) {
    long long sum = 0;
    
    for (; c; c -= (c & -c)) {
        sum += fw[c];
    }
    for (--b; b; b -= (b & -b)) {
        sum -= fw[b];
    }
    
    return sum;
}