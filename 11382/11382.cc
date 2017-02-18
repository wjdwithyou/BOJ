#include <iostream>

int main() {
    unsigned long long int t;
    unsigned long long int s = 0;
    
    for (int i = 0; i < 3; ++i) {
        scanf("%llu", &t);
        s += t;
    }
    
    printf("%llu", s);
    return 0;
}