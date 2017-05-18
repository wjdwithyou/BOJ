#include <iostream>

#define DIV 14579

int main() {
    int a, b;
    int r = 1;
    
    scanf("%d %d", &a, &b);
    
    for (int i = a; i <= b; ++i) {
        r *= ((i * (i + 1)) >> 1) % DIV;
        r %= DIV;
    }
    
    return !printf("%d", r);
}