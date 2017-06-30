#include <iostream>

int main() {
    int n, m;
    
    scanf("%d", &n);
    
    m = n >> 1;
    
    return !printf("%d", m * m + ((n & 1) ? 3 * m + 2 : 2 * m + 1));
}