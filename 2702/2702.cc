#include <iostream>

int getGCD(int, int);

int main() {
    int t, a, b, g;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d %d", &a, &b);
        
        g = getGCD(a, b);
        
        printf("%d %d\n", a * b / g, g);
    }
    
    return 0;
}

int getGCD(int a, int b) {
    int t;
    
    if (a > b) {
        t = b;
        b = a;
        a = t;
    }
    
    do {
        t = b % a;
        b = a;
        a = t;
    } while (a);
    
    return b;
}