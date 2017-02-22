#include <iostream>

int main() {
    int a, b, c, d, p, x, y;
    
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);
    
    x = p * a;
    y = b + d * ((p - c) > 0 ? p - c : 0);
    
    printf("%d", (x < y) ? x : y);
    return 0;
}