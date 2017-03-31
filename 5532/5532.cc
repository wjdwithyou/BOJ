#include <iostream>

int main() {
    int l, a, b, c, d;
    
    scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
    
    a = a / c + (a % c != 0);
    b = b / d + (b % d != 0);
    
    l -= (a > b) ? a : b;
    
    printf("%d", (l > 0) ? l : 0);
    return 0;
}