#include <iostream>

int getGCD(int, int);

int main() {
    int n, m, g;
    
    scanf("%d:%d", &n, &m);
    
    g = getGCD(n, m);
    
    printf("%d:%d", n / g, m / g);
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