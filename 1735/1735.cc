#include <iostream>

int getGCD(int, int);

int main() {
    int a, b, c, d, g, x, y;
    
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);
    
    g = getGCD(b, d);
    
    x = (a * d + c * b) / g;
    y = (b * d) / g;
    
    g = getGCD(x, y);
    
    printf("%d %d", x / g, y / g);
    return 0;
}

int getGCD(int x, int y) {
    int t;
    
    if (x > y) {
        t = y;
        y = x;
        x = t;
    }
    
    do {
        t = y % x;
        y = x;
        x = t;
    } while (x);
    
    return y;
}