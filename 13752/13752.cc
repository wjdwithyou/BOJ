#include <iostream>

int main(void) {
    int n, k;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        
        for (int j = 0; j < k; ++j) {
            printf("=");
        }
        puts("");
    }
    
    return 0;
}