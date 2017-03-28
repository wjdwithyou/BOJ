#include <iostream>

int getGCD(unsigned long long int, unsigned long long int);

int main() {
    unsigned long long int a, b;
    
    scanf("%llu %llu", &a, &b);
    
    for (int i = getGCD(a, b); i > 0; --i) {
        printf("1");
    }
    
    return 0;
}

int getGCD(unsigned long long int a, unsigned long long int b) {
    unsigned long long int t;
    
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
    
    return static_cast<int>(b);
}