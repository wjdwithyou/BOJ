#include <iostream>

int main() {
    int a, b, v, d;
    
    scanf("%d %d %d", &a, &b, &v);
    
    v -= a;
    d = a - b;
    
    printf("%d", v / d + (v % d != 0) + 1);
    return 0;
}