#include <iostream>

#define MAX 1000000000

unsigned long long int d[131072];

int main() {
    int n;
    unsigned long long p;
    unsigned long long min = MAX + 1;
    unsigned long long int sum = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n - 1; ++i) {
        scanf("%llu", &d[i]);
    }
    
    for (int i = 0; i < n - 1; ++i) {
        scanf("%llu", &p);
        
        if (min > p) {
            min = p;
        }
        
        sum += min * d[i];
    }
    scanf("%llu", &p);
    
    printf("%llu", sum);
    return 0;
}