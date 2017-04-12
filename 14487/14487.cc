#include <iostream>

int main() {
    int n, t;
    int sum = 0, max = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        
        sum += t;
        
        if (max < t) {
            max = t;
        }
    }
    
    printf("%d", sum - max);
    return 0;
}