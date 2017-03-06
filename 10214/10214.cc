#include <iostream>

int main() {
    int t, y, k, a, b;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        a = b = 0;
        
        for (int j = 0; j < 9; ++j) {
            scanf("%d %d", &y, &k);
            
            a += y;
            b += k;
        }
        
        if (a > b) {
            puts("Yonsei");
        } else if (a < b) {
            puts("Korea");
        } else {
            puts("Draw");
        }
    }
    
    return 0;
}