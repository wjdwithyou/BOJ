#include <iostream>

int main() {
    int t, min, sum;
    
    sum = 0;
    min = 2048;
    
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &t);
        
        if (min > t) {
            min = t;
        }
    }
    
    sum += min;
    min = 2048;
    
    for (int i = 0; i < 2; ++i) {
        scanf("%d", &t);
        
        if (min > t) {
            min = t;
        }
    }
    
    sum += min;
    
    printf("%d", sum - 50);
    return 0;
}