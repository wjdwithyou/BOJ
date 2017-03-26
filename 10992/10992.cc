#include <iostream>

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 1; i < n; ++i) {
        for (int j = n - i; j > 0; --j) {
            printf(" ");
        }
        
        if (i == 1) {
            puts("*");
            continue;
        }
        
        printf("*");
        
        for (int j = 0; j < 2 * i - 3; ++j) {
            printf(" ");
        }
        
        puts("*");
    }
    
    for (int j = 0; j < 2 * n - 1; ++j) {
        printf("*");
    }
    
    return 0;
}