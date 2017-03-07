#include <iostream>

int main() {
    int t, n;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d", &n);
        
        for (int j = 0; j < n; ++j) {
            if (j == 0 || j == n - 1) {
                for (int k = 0; k < n; ++k) {
                    printf("#");
                }
            } else {
                for (int k = 0; k < n; ++k) {
                    printf((k == 0 || k == n - 1) ? "#" : "J");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}