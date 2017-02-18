#include <iostream>

int main() {
    int t, k, r;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        r = 1;
        
        scanf("%d", &k);
        
        for (int j = 0; j < k; ++j, r <<= 1);
        
        printf("%d\n", r - 1);
    }
    
    return 0;
}