#include <iostream>

int main() {
    int n, m;
    
    scanf("%d %d", &n, &m);
    printf("%u", (n > m)? n - m : m - n);
    
    return 0;
}