#include <iostream>

int main() {
    int t, n;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d", &n);
        printf("Pairs for %d:", n);
        
        for (int j = 1; j < n - j; ++j) {
            printf((j == 1) ? " %d %d" : ", %d %d", j, n - j);
        }
        printf("\n");
    }
    
    return 0;
}