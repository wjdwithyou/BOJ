#include <iostream>

int main() {
    int a, b;
    
    do {
        scanf("%d %d", &a, &b);
        a += b;
        
        if (a) {
            printf("%d\n", a);
        }
    } while (a);
    
    return 0;
}