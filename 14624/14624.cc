#include <iostream>

int main() {
    int n;
    
    scanf("%d", &n);
    
    if (!(n & 1)) {
        return !printf("I LOVE CBNU");
    }
    
    for (int i = 0; i < n; ++i) {
        printf("*");
    }
    
    puts("");
    
    for (int i = n >> 1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            printf(" ");
        }
        printf("*");
        
        if (i == n >> 1) {
            puts("");
            continue;
        }
        
        for (int j = n - 2 * i - 2; j > 0; --j) {
            printf(" ");
        }
        puts("*");
    }
    
    return 0;
}