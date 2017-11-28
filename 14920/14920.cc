#include <iostream>

int main(void) {
    int n;
    int i = 1;
    
    for (scanf("%d", &n); n > 1; ++i, n = (n & 1) ? 3 * n + 1 : (n >> 1));
    
    return !printf("%d", i);
}