#include <iostream>

int main() {
    int n, input, temp;
    int sum = 0;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &input);
        
        temp = input * i - sum;
        
        printf("%d ", temp);
        
        sum += temp;
    }
    
    return 0;
}