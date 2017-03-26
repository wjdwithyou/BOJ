#include <iostream>

int main() {
    int n, t;
    
    scanf("%d", &n);
    
    while (true) {
        scanf("%d", &t);
        
        if (!t) {
            break;
        }
        
        printf("%d is%s a multiple of %d.\n", t, (t % n) ? " NOT" : "", n);
    }
    
    return 0;
}