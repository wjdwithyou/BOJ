#include <iostream>

int main() {
    int n, a, b;
    
    scanf("%d %d %d", &n, &a, &b);
    
    --a;
    --b;
    
    for (int i = 1;; ++i) {
        a >>= 1;
        b >>= 1;
        
        if (a == b) {
            printf("%d", i);
            break;
        }
    }
    
    return 0;
}