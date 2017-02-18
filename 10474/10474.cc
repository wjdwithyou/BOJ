#include <iostream>

int main() {
    int u, d;
    
    while (true) {
        scanf("%d %d", &u, &d);
        
        if (u == 0 && d == 0) {
            break;
        }
        
        printf("%d %d / %d\n", u / d, u % d, d);
    }
    
    return 0;
}