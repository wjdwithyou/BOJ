#include <iostream>

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = n - i; j > 0; --j) {
            printf(" ");
        }
        
        printf("*");
        
        if (i == 1) {
            puts("");
            continue;
        }
        
        for (int j = 0; j < i * 2 - 3; ++j) {
            printf(" ");
        }
        
        puts("*");
    }
    
    return 0;
}