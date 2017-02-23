#include <iostream>

int main() {
    unsigned long long int a, b, temp, o_a, o_b;
    
    scanf("%llu %llu", &a, &b);
    
    o_a = a;
    o_b = b;
    
    if (a > b) {
        temp = b;
        b = a;
        a = temp;
    }
    
    while (b % a) {
        temp = b % a;
        b = a;
        a = temp;
    }
    
    printf("%llu\n", (o_a * o_b) / a);
    return 0;
}