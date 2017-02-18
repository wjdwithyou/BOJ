#include <iostream>

int main() {
    int t, min, sum;
    
    sum = 0;
    min = 128;
    
    for (int i = 0; i < 4; ++i) {
        scanf("%d", &t);
        
        sum += t;
        
        if (min > t) {
            min = t;
        }
    }
    
    sum -= min;
    min = 128;
    
    for (int i = 0; i < 2; ++i) {
        scanf("%d", &t);
        
        sum += t;
        
        if (min > t) {
            min = t;
        }
    }
    
    sum -= min;
    
    printf("%d", sum);
    return 0;
}