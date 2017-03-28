#include <iostream>

int a[1048576];

int main() {
    int n, b, c, t;
    unsigned long long cnt;
    
    scanf("%d", &n);
    
    cnt = n;
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    
    scanf("%d %d", &b, &c);
    
    for (int i = 0; i < n; ++i) {
        t = a[i] - b;
        
        if (t <= 0) {
            continue;
        }
        
        cnt += t / c + (t % c != 0);
    }
    
    printf("%llu", cnt);
    return 0;
}