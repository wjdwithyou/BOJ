#include <iostream>

int main() {
    int n, b;
    
    for (int i = 1;; ++i) {
        scanf("%d", &n);
        
        if (!n) {
            break;
        }
        
        b = ((n * 3) & 1);
        
        printf("%d. %s %d\n", i, (b) ? "odd" : "even", (n - b) >> 1);
    }
    
    return 0;
}