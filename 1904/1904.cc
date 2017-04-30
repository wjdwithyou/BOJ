#include <iostream>

#define DIV 15746

int main() {
    int n, a, b, t;
    
    a = b = 1;
    
    scanf("%d", &n);
    
    for (int i = 2; i <= n; ++i) {
        t = b;
        b = (a + b) % DIV;
        a = t;
    }
    
    return !printf("%d", b);
}