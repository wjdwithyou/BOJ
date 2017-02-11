#include <iostream>

int main() {
    int n, s;
    
    while (true) {
        s = 0;
        
        scanf("%d", &n);
        
        if (n == 0) {
            break;
        }
        
        for (int i = 1; i <= n; ++i) {
            s += (i * i);
        }
        
        printf("%d\n", s);
    }
    
    return 0;
}