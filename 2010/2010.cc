#include <iostream>

int main() {
    int n, t;
    int sum = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        sum += t;
    }
    
    printf("%d", sum - n + 1);
    return 0;
}