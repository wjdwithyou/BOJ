#include <iostream>

int req[131072];

int main() {
    int n, t, budget;
    int max = 0, sum = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        
        ++req[t];
        sum += t;
        
        if (max < t) {
            max = t;
        }
    }
    
    scanf("%d", &budget);
    
    while (sum > budget) {
        req[max - 1] += req[max];
        sum -= req[max--];
    }
    
    printf("%d", max);
    return 0;
}