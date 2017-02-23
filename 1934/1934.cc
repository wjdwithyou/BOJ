#include <iostream>

int main() {
    int t, a, b, temp, o_a, o_b;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d %d", &a, &b);
        
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
        
        printf("%d\n", (o_a * o_b) / a);
    }
    
    return 0;
}