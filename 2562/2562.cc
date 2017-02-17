#include <iostream>

int main() {
    int n, idx;
    int max = 0;
    
    for (int i = 1; i <= 9; ++i) {
        scanf("%d", &n);
        
        if (max < n) {
            idx = i;
            max = n;
        }
    }
    
    printf("%d\n%d", max, idx);
    return 0;
}