#include <iostream>

int main() {
    int n, t;
    int min = 1048576, max = -1048576;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        
        if (min > t) {
            min = t;
        }
        if (max < t) {
            max = t;
        }
    }
    
    printf("%d %d", min, max);
    return 0;
}