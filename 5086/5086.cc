#include <iostream>

int main() {
    unsigned long long int a, b;
    
    while (true) {
        scanf("%llu %llu", &a, &b);
        
        if (!a && !b) {
            break;
        }
        
        if (!(b % a)) {
            puts("factor");
        } else if (!(a % b)) {
            puts("multiple");
        } else {
            puts("neither");
        }
    }
    
    return 0;
}