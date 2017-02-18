#include <iostream>

int main() {
    int t, a, b, c;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d %d", &a, &b);
        
        c = a / b;
        
        printf("%d\n", c * c);
    }
    
    return 0;
}