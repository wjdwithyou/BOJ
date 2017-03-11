#include <iostream>

int main() {
    int n;
    
    while (true) {
        scanf("%d", &n);
        
        if (!n) {
            break;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                printf("*");
            }
            printf("\n");
        }
    }
    
    return 0;
}