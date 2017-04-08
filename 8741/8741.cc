#include <iostream>

int main() {
    int k;
    
    scanf("%d", &k);
    
    for (int i = 0; i < k; ++i) {
        printf("%d", 1);
    }
    for (int i = 1; i < k; ++i) {
        printf("%d", 0);
    }
    
    return 0;
}