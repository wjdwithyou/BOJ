#include <iostream>

int getGCD(int, int);

int main() {
    int n, b, t, g;
    
    scanf("%d", &n);
    scanf("%d", &b);
    
    for (int i = 1; i < n; ++i) {
        scanf("%d", &t);
        
        g = getGCD(b, t);
        
        printf("%d/%d\n", b / g, t / g);
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