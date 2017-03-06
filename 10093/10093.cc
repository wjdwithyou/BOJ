#include <iostream>

int main() {
    unsigned long long int a, b, t;
    
    scanf("%llu %llu", &a, &b);
    
    if (a == b) {
        ++b;
    } else if (a > b) {
        t = a;
        a = b;
        b = t;
    } else;
    
    printf("%llu\n", b - ++a);
    
    for (unsigned long long int i = a; i < b; ++i) {
        printf("%llu ", i);
    }
    
    return 0;
}