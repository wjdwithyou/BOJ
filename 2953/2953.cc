#include <iostream>

int main() {
    int t, sum, idx;
    int max = 0;
    
    for (int i = 1; i <= 5; ++i) {
        sum = 0;
        
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &t);
            sum += t;
        }
        
        if (max < sum) {
            idx = i;
            max = sum;
        }
    }
    
    printf("%d %d", idx, max);
    return 0;
}