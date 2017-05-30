#include <iostream>

int getGCD(int, int);

int main() {
    int n, a, b;
    
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    
    a = getGCD(a, b);
    
    if (n == 3) {
        scanf("%d", &b);
        a = getGCD(a, b);
    }
    
    b = a >> 1;
    
    for (int i = 1; i <= b; ++i) {
        if (a % i) {
            continue;
        }
        
        printf("%d\n", i);
    }
    
    return !printf("%d", a);
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