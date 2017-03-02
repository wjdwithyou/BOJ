#include <iostream>

#define NUM_PARTS 5

int main() {
    double price[8] = { 350.34, 230.90, 190.55, 125.30, 180.90 };
    double sum;
    int t, n;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        sum = 0;
        
        for (int j = 0; j < NUM_PARTS; ++j) {
            scanf("%d", &n);
            sum += n * price[j];
        }
        
        printf("$%.2f\n", sum);
    }
    
    return 0;
}