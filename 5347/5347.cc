#include <iostream>

int getGCD(int, int);

int main() {
    int n, a, b;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        printf("%lld\n", static_cast<long long int>(a) * b / getGCD(a, b));
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