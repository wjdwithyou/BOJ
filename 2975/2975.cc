#include <iostream>

int main() {
    int a, b;
    char c;
    
    while (1) {
        scanf("%d %c %d", &a, &c, &b);
        
        if (!b) {
            break;
        }
        
        a += (c == 'W') ? -b : b;
        
        if (a < -200) {
            puts("Not allowed");
        } else {
            printf("%d\n", a);
        }
    }
    
    return 0;
}