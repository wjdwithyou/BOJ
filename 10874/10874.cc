#include <iostream>

int main() {
    int pattern[16] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
    int n, t, cheat;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        cheat = 1;
        
        while (getchar() != '\n');
        
        for (int j = 0; j < 10; ++j) {
            scanf("%d", &t);
            
            if (pattern[j] != t) {
                --cheat;
                break;
            }
        }
        
        if (cheat) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}