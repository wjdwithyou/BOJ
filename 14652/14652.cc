#include <iostream>

int main(void) {
    int n, m, k;
    
    scanf("%d %d %d", &n, &m, &k);
    
    return !printf("%d %d", k / m, k % m);
}