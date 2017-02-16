#include <iostream>

int main() {
    int n;
    int s = 0, min = 128;
    
    for (int i = 0; i < 7; ++i) {
        scanf("%d", &n);
        
        if (n & 1) {
            s += n;
            
            if (min > n) {
                min = n;
            }
        }
    }
    
    if (s) {
        printf("%d\n%d", s, min);
    }
    else {
        printf("-1");
    }
    
    return 0;
}