#include <iostream>

int main() {
    int k, n, m, d;
    
    scanf("%d %d %d", &k, &n, &m);
    
    d = k * n - m;
    
    printf("%d", (d > 0) ? d : 0);
    return 0;
}