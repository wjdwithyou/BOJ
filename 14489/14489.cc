#include <iostream>

int main() {
    int a, b, c;
    
    scanf("%d %d", &a, &b);
    scanf("%d", &c);
    
    c *= 2;
    
    printf("%d", (c > a + b) ? a + b : a + b - c);
    return 0;
}