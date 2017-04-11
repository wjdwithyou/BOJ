#include <iostream>

long long int f[128];

int main() {
    int n;
    
    scanf("%d", &n);
    
    f[1] = f[2] = f[3] = 1;
    
    for (int i = 4; i <= n; ++i) {
        f[i] = f[i - 1] + f[i - 3];
    }
    
    printf("%lld", f[n]);
    return 0;
}